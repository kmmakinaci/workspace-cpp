#include <iostream>

class Base{
    public:
    void foo(){
        std::cout << "Base::foo()\n";
    }

    void foo(int){
        std::cout << "Base::foo(int)\n";
    }
};

class Der : public Base {
    public:
    using Base::Base;
    void foo(int){
        std::cout << "der::foo(int)\n";
    }
};

int main(){
    Der d;
    d.foo(3);
    return 0;
}