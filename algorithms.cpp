/*DISCLAIMER
This code is from the https://www.youtube.com/watch?v=eJCA2fynzME&t=1443s
Back to Basics: (Range) Algorithms in C++ - Klaus Iglberger - CppCon 2023
*/
#include "stdio.h"
#include <vector>
#include <algorithm>
#include <numeric>

//partition
int partition()
{

    std::vector<Person> table = /* ...*/;

    auto const pos =
    std::ranges::stable_partition(table, [](Person const& p))
    {
        return isChild(p);
        //return isSeniorCitizen(p);
    }

    std::ranges::rotate(table, pos);
}

int accumulate()
{
    std::vector<Person> table = /*...*/;
    
    //even drop the initial value here
    auto const sum =
        std::reduce(std::execution::par,
            std::begin(table), std::end(table), double{} );

    std::cout << "Total age = " << sum << '\n';

    // ...
}