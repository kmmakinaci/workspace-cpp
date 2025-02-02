#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

std::mutex print_mutex;

void playFizzBuzz(const std::vector<std::string>& names, int rounds){
    
}

void threadedFizzBuzz(const std::vector<std::string>& names, int rounds){
    std::thread threadFizzBuzz(playFizzBuzz, names, rounds);
    threadFizzBuzz.join();
}

int main() {
    //List of players
    std::vector<std::string> names = {"Abdul", "Bart", "Claudia", "Divya"};
    constexpr int rounds{50};

    std::cout << "Playing FizzBuzz in the main thread" << std::endl;
    playFizzBuzz(names,rounds);

    std::cout << "Playing FizzBuzz with multi thread" << std::endl;
    threadedFizzBuzz(names,rounds);

    return 0;
}