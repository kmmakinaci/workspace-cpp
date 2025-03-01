#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <memory>
#include <string>

class SerialPort {
public: 
    
    SerialPort(const std::string& port, int baudrate){
        serial_fd = open(port.c_str(), O_RDWR | O_NOCTTY);
        if (serial_fd < 0) {
            throw std::runtime_error("Failed to open serial port!");
        }
        configureTTY(serial_fd, baudrate);
    }
    ~SerialPort() {
        if (serial_fd >= 0) {
            close(serial_fd);
        }
    }

    //Move constructor
    SerialPort(SerialPort&& other) noexcept : serial_fd(other.serial_fd) {
        other.serial_fd = -1; //prevent double close
    };

    //Move assignment
    SerialPort& operator=(SerialPort&& other) noexcept{
        if (this != &other){
            if(serial_fd >= 0)
                close(serial_fd);
            serial_fd = other.serial_fd;
            other.serial_fd = -1;
        }
        return *this;
    }

    //Delete copy constructor and copy assignment - serial fd cannot copiable
    SerialPort(const SerialPort&) = delete;
    SerialPort& operator=(const SerialPort&) = delete;

    void write(const std::string& data) {
        ::write(serial_fd, data.c_str(), data.size());
    }

    std::string read() {
        char buffer[256];
        int n = ::read(serial_fd, buffer, sizeof(buffer));
        if n >= 0 {
            return std::string(buffer, n);
        }
        return {};
    }   
private:
    int serial_fd;

    configureTTY(int serial_fd, int baudrate){
        struct termios tty;
        memset(&tty, 0, sizeof(tty));
        
        if(tcgetattr(serial_fd, &tty) != 0){
            throw std::runtime_error("Failed to get serial port attributes!");
        }

        cfsetospeed(&tty, baudrate);
        cfsetispeed(&tty, baudrate);
        tty.c_cflag |= (CLOCAL | CREAD);
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8;
        tty.c_cflag &= ~PARENB;
        tty.c_cflag &= ~CSTOPB;

        if(tcsetattr(serial_fd, TCSANOW, &tty) != 0){
            throw std::runtime_error("Failed to set serial port attributes!");
        }
    }
};

#define SERIAL_PORT "/dev/ttyUSB0"
#define BAUD_RATE B115200

int main() {
    try {
        SerialPort com_serial(SERIAL_PORT, BAUD_RATE);
        com_serial.write("AT\r\n");
        std::string response = com_serial.read();
        if (!response.empty()) {
            std::cout << "Received: " << response << std::endl;
        }   
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
