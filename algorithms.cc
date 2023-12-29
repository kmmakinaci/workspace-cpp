/*DISCLAIMER
This code is from the https://www.youtube.com/watch?v=eJCA2fynzME&t=1443s
Back to Basics: (Range) Algorithms in C++ - Klaus Iglberger - CppCon 2023
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

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
    
    // Prefer to keep things immutable.
    // Anti pattern : Initialize then modify

    auto const age =
        std::accumulate( std::begin(table), std::end(table), 0,
        [](int age, Person const& p )
        {
            return age + p.age;
        } );

    std::cout << "Total age = " << age << '\n';

    // ...
}