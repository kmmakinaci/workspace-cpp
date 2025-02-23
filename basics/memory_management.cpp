/*
 * unique_ptr: Owns and object exclusively. (cannot be copied but moved)
 * shared_ptr: Shared (multiple) ownership of an object. (can be copied, uses reference counting)
 * weak_ptr: Observes a shared_ptr without owning(without increasing the reference count) prevents circular dependencies.
*/

#include <iostream>
#include <memory>

class MemoryTest {
    public:
        MemoryTest() {std::cout << "MemoryTest constructor" << std::endl;}
        ~MemoryTest() {std::cout << "MemoryTest destructor" << std::endl;}
};

int main() {
    std::shared_ptr<MemoryTest> sharedPtr = std::make_shared<MemoryTest>();
    std::unique_ptr<MemoryTest> uniquePtr = std::make_unique<MemoryTest>();
    std::weak_ptr<MemoryTest> weakPtrSp = sharedPtr;
    
    // Locking a valid weak pinter
    if (auto lockedPtr = weakPtrSp.lock()) {
        std::cout << "Weak pointer is valid" << std::endl;
    } else {
        std::cout << "Weak pointer is invalid" << std::endl;
    }

    // Locking an invalid weak pointer
    sharedPtr.reset();
    if (auto lockedPtr = weakPtrSp.lock()){
        std::cout << "Weak pointer is valid" << std::endl;
    } else {
        std::cout << "Weak pinter is not valid" << std::endl;
    }

    return 0;
}
