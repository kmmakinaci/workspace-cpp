#include <iostream>
#include <cstdint>
#include <sstream>
#include <iomanip>

std::string extractSourceMacAdress (std::istream& inputStream){
    std::stringstream macAdress;

    for(int i = 0; i<6; i++){
        int byte;
        inputStream >> std::hex >> byte;
        macAdress << std::hex << std::setw(2) << std::setfill('0') << byte;
        if(i < 5){
            macAdress << ":";
        }
    }

    return macAdress.str();

}

int main(){
    //example ethernet frame
    //uint8_t frame[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00, 0x10, 0x00};

    std::cout << "Enter the captured ethernet frame (6 bytes in hexadecimal): ";

    //Read the input 
    std::stringstream inputStream;
    std::string input;
    std::getline(std::cin, input);
    inputStream << input;

    //Extract to source MAC address
    std::string sourceMacAddress = extractSourceMacAdress(inputStream);

    //print the source MAC adress
    std::cout<< "Source MAC Adress: " << sourceMacAddress << std::endl;

    return 0;
}