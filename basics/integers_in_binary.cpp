#include <iostream>
#include <bitset>

int main() {
    unsigned short int data {0b11111110};
    std::cout << "data (dec) : " << std::dec << data << std::endl;
    std::cout << "data (hex) : " << std::hex << std::showbase << data << std::endl;
    std::cout << "data (bin) : " << std::bitset<16>(data) << std::endl;

    bool test = data.any(); //any of bit value == 1 
    size_t cnt = data.count();  //count of 1 bits

    std::cout << "data.any() : " << test << std::endl;
    std::cout << "data.count() : " << cnt << std::endl;

    return 0;
}