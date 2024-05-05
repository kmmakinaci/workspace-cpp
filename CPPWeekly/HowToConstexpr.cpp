/*
Please see the reference : https://www.youtube.com/watch?v=4pKtPWcl1Go
*/
#include<array>

constexpr int get_value(int value)
{
    return value*2;
}

constexpr std::array<int, 1000> get_values() {
    std::array<int, 1000> retval{};
    int count = 0;
    for(auto &val : retval) {
        val = count * 3;
        ++count;
    }
    return retval;
}

// int main()
// {
//     //int value = get_value(6);
//     const int value = get_value(6);
//     //constexpr int value = get_value(6); 
//     /*
//     Is value calculated at compile time ?
//     without int, its compiletime evaluation is up to compiler
//     */

//     static_assert(value == 12); //forces compile time caluclation
//     return value;
// }

int main()
{
    const int *p = nullptr;

    //you rarely want constexpr variables!!

    {
        //you almost always measn static constexpr instead!
        
        //it forces initialization at compile time
        //through the means of "constant initialization"
        static constexpr auto values = get_values();
        //constexpr values are stack values! (unless they static)
            // 6.9.3.2
        p = &values[985];
    }
        //it was not required to this
    return values[879];
}