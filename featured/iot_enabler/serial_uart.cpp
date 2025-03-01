#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>

int main() {
    int serial_fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY);
    if (serial_fd < 0) {
        std::cerr << "Failed to open serial port!" << std::endl;
        return -1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    tcgetattr(serial_fd, &tty);

    cfsetospeed(&tty, B115200);
    cfsetispeed(&tty, B115200);

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;

    tcsetattr(serial_fd, TCSANOW, &tty);

    char at_command[] = "AT\r\n";
    write(serial_fd, at_command, sizeof(at_command));

    char buffer[256];
    int n = read(serial_fd, buffer, sizeof(buffer));
    if(n>0) {
        buffer[n] = '\0';
        std::cout << "Received: " << buffer << std::endl;
    }

    close(serial_fd);
    return 0;
}