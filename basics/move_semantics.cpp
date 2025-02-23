/*
 * Move semantics (std::move) transfers ownership of resources instead of copying,
    preventing unnecessary allocations.
 * Uses rvalue references (T&&)
*/

#include <iostream>
#include <vector>

class MoveExample {
public:
    std::vector<int> data;

    // Constructor that initializes the vector with a given size
    MoveExample(size_t size) : data(size) {
        std::cout << "Constructor" << std::endl;
    }

        // noexcept  allows for certain optimizations and ensures strong exception safety guarantees
    MoveExample(MoveExample&& other) noexcept : data(std::move(other.data)){
        std::cout << "Move constructor" << std::endl;
    }

        MoveExample& operator=(MoveExample&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
        }
        std::cout << "Move assignment operator" << std::endl;
        return *this;
    }
};

int main() {
    MoveExample obj1(10);

    // Use the move constructor to transfer resources from obj1 to obj2
    MoveExample obj2 = std::move(obj1); // Move constructor
    
    // At this point, obj1 and obj2 are in a valid but unspecified state
    // They should not be used except for destruction or assignment
    
    // Create another instance of MoveExample with a vector of size 20
    MoveExample obj3(20);
    
    // Use the move assignment operator to transfer resources from obj2 to obj3
    obj3 = std::move(obj2); // Move assignment operator

    // At this point, obj1 and obj2 are in a valid but unspecified state
    // They should not be used except for destruction or assignment

    return 0;
}