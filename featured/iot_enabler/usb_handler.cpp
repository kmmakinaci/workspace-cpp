/*
    Uses libusb to enumerate USB devices.
    Prints the number of connected USB devices.
*/
#include <libusb-1.0/libusb.h>
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>

class USBDevice {
public:
    USBDevice(uint16_t vendor_id, uint16_t product_id) {
        if (libusb_init(&ctx) < 0) {
            throw std::runtime_error("Failed to initialize libusb!");
        }

        handle = libusb_open_device_with_vid_pid(ctx, vendor_id, product_id);
        if (!handle) {
            libusb_exit(ctx);
            throw std::runtime_error("USB Device not found!");
        }
    }

    ~USBDevice() {
        if (handle) {
            libusb_close(handle);
        }
        libusb_exit(ctx);
    }

    void sendData(const std::vector<uint8_t>& data, uint8_t endpoint) {
        int transferred;
        int result = libusb_bulk_transfer(handle, endpoint, const_cast<uint8_t*>(data.data()), data.size(), &transferred, 1000);
        if (result != LIBUSB_SUCCESS) {
            throw std::runtime_error("Failed to send data to USB device!");
        }
        std::cout << "Sent " << transferred << " bytes" << std::endl;
    }

private:
    libusb_context* ctx = nullptr;
    libusb_device_handle* hadle = nullptr;
};

#define VENDOR_ID 0x1234
#define PRODUCT_ID 0x5678
#define ENDPOINT_OUT 0x01

int main() {
    try {
        USBDevice usb_device(VENDOR_ID, PRODUCT_ID);
        std::vector<uint8_t> data_out = {'H', 'e', 'l', 'l', 'o', ' ', 'U', 'S', 'B'};
        usb_device.sendData(data_out, ENDPOINT_OUT);

        // SerialPort class usage will be added later
        // SerialPort serial_port("/dev/ttyUSB0", B115200);
        // serial_port.write("AT\r\n");
        // std::string response = serial_port.read();
        // if (!response.empty()) {
        //     std::cout << "Received from serial: " << response << std::endl;
        // } else {
        //     std::cout << "No response received from serial." << std::endl;
        // }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;