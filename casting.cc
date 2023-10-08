#include <stddef.h>
#include <iostream>

class Base
{
    void print()
    {
        std::cout << "Base" << std::endl;
    }
};

// Derived Class 1 declaration
class Derived1 : public Base
{
    void print()
    {
        std::cout << "Derived1" << std::endl;
    }
};

// Derived class 2 declaration
class Derived2 : public Base
{
    void print()
    {
        std::cout << "Derived2" << std::endl;
    }
};

int main()
{
    /*
    reinterpret_cast:
    Converts a pointer of some data type to
    a pointer of another data type
    data_type *var_name =
           reinterpret_cast <data_type *>(pointer_variable);
    */
    int *p = new int(65);
    char *ch = reinterpret_cast<char *>(p);
    std::cout << "interger: " << *p << ";" << std::endl;
    std::cout << "character: " << *ch << ";" << std::endl;

    /*
    static_cast:
    It is udes to do implicit conversions. It is a compile time cast
    Gives compile error when illegal typecast conversion.
    */
    float f = 3.5;
    int a = f; // this how we do in C
    int b = static_cast<int>(f);

    /*const_cast:
    It is used to change the constant value(nature) of
    any object.
    */
    const int a = 50;
    const int *y = &a;
    int *z = const_cast<int *>(y);
    *z = 100;

    /*
    dynamic_cast:
    A cast is an operator that converts data from one type to another type.
    In C++, dynamic casting is mainly used for safe downcasting at run time.
    To work on dynamic_cast there must be one virtual function in the base
    class. A dynamic_cast works only polymorphic base class because it uses
    this information to decide safe downcasting.
    */
    Derived1 d1;

    // Base class pointer hold Derived1
    Base *bp = dynamic_cast<Base *>(&d1);

    // Dynamic casting
    Derived2 *dp2 = dynamic_cast<Derived2 *>(bp);
    if (dp2 == nullptr)
        std::cout << "null" << std::endl;

    return 0;
}