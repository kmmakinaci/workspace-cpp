#include <iostream>

class Base{
    public:
    Base(){
        std::cout << "Base()\n";
    }
    protected: //Base classların descructorları protected yapılarak base 
    //classların derived classlar tarından destruct edilmesi önlenir.
    virtual ~Base(){//eger virtual olmazsa derivated dtor cagirilmaz
        std::cout << "~Base()\n";
    }
};

class Der : public Base{
    public:    Der(){
        std::cout << "Der()\n";
    }

    ~Der(){
        std::cout <<  "~Der()\n";
    }
};

int main(){
    Base* ptr = new Der; //upcasting 
    //bu kullanımı tercih etmiyoruz.
    //delete ptr;
}