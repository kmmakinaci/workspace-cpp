//Please see reference: https://www.youtube.com/watch?v=aC-aAiS5Wuc
#include <functional>
#include <vector>

// C++ lambda IS NOT sd::function

//lambda: a C++ language construct for defining an anonymous function
// std::function a type-erased wrapper around a "callable"

    //Section2 - optimized build
int add(int x, int y)
{
    return x+y;
}

int call(int (*f)(int, int)){
    return f(2,3);
}

int call(const std::function<int (int, int)> &f)
{
    return f(2,3);
}


int main()
{
    //Section1 - unoptimized build
//     auto add = [](const int x, const int y)
//     {
//         return x + y;
//     };

//     // this is a holder a function, not a function itself
//     //std::function<int (const int, const int)> func; 
//     std::function<int (const int, const int)> func(add);
//     //return add(4,5);
//     return func(4,5);

    //Section 3 - Abstrac behavior
    int valDef = 15;
    std::vector<std::function<int (int, int)>> operations;

    operations.emplace_back([](int x, int y){return x + y;});
    operations.emplace_back([](int x, int y){return x * y;});
    operations.emplace_back([](int x, int y){return x - y;});
    operations.emplace_back([=](int x, int y){return valDef + x - y;});

    /*
    std::vector<int (*)(int, int)> operations;

    operations.emplace_back([](int x, int y){return x + y;});
    operations.emplace_back([](int x, int y){return x * y;});
    operations.emplace_back([](int x, int y){return x - y;});
    operations.emplace_back([=](int x, int y){return valDef + x - y;});

    operations.emplace_back(add);
    */


}