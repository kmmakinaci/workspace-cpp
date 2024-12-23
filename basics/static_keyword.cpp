/* In C++ 'static' keyword is used to declare a variable with a special lifetime and linkage
affecting its scope and visibility.
1. Variable inside a function
When a static variable is declared inside a function, it retains its value between function calls
meaning the variable is not reinitialiyed every time the function is invoked. Lifetime extends for
the entire execution of the program, but scope is limited to function.
2: Variable at Class LevelWhen a variable is declared as static inside a class,it means the variable
is shared by akk uinstances of the class rather than each onstance having its own copy. This is
commonly used for class-wide data.
*/
#include <iostream>

void counterFunction() {
    static int counter{0};
    std::cout << "The counter: " << counter << std::endl;
    counter++;
}

class MyClass {
public:
    static int objectCount;
    //static inline int objectCount{0};  // C++17-Both declaration and definition
    MyClass() {
        objectCount++;
    }

    static void displayCount() {
        std::cout << "Number of objects: " << objectCount << std::endl;
    }
};

// Initialize thge static member outside of the class definition
int MyClass::objectCount{0};

int main() {
    counterFunction();
    counterFunction();

    MyClass obj1;
    MyClass obj2;
    obj1.displayCount();
    obj2.displayCount();
    MyClass::displayCount();
    return 0;
}