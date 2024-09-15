#include <iostream>
#include "TinyUrl.hpp"

int main (void){
    TinyUrl coder;
    const std::string longUrl = "https://leetcode.com/problems/design-tinyurl";
    std::string tinyUrl = coder.encode(longUrl);
    std::string originalUrl = coder.decode(tinyUrl);

    std::cout<<"Original URL:"<<originalUrl<<" --> tinyURL:"<<tinyUrl<<std::endl;
    return 0;
}