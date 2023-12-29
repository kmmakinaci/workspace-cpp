#include <vector>

//partition
int partition(){

    std::vector<Person> table = /* ...*/;

    std::ranges::partition(table, [](Person const& p))
    {
        return isChild(p);
        //return isSeniorCitizen(p);
    }
}