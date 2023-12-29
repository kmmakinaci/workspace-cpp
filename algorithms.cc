/*DISCLAIMER
This code is from the https://www.youtube.com/watch?v=eJCA2fynzME&t=1443s
Back to Basics: (Range) Algorithms in C++ - Klaus Iglberger - CppCon 2023
*/
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

    int total_age = 0;
    for( auto const& person : table) {
        total_age += person.age;
    }
    std::cout << "Total age =" << total_age << '\n';

    // ...
}