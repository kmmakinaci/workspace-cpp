#include <iostream>
#include <variant>

#define CALL_VALUE_CATG(x) std::cout << "\"" << #x << "\"" \
                                     << "is: " << Valcat<decltype((x))>::valcat << "n"

template <typename T>
struct Valcat
{
    constexpr static const char *valcat = "R value";
};

template <typename T>
struct Valcat<T &>
{
    constexpr static const char *valcat = "L value";
};

template <typename T>
struct Valcat<T &&>
{
    constexpr static const char *valcat = "X value";
};

/**
 * @brief variant
 *
 * An alternative method to check if variant has a type
 *
 */
template <typename T, typename..Ts>
constexpr bool _has_type() const std::variant<Ts...> &var,
    std::index_sequence<Is...>
{
    return (
        (std::is_same_v < T, std::variant_alternative_t < Is, std::decay_t < decltype(var) >>>>) | ...);
}

template <typename T, typename... Ts>
constexpr bool has_type(const std::variant<Ts...>& var){
    return _has_type<T>(var, std::index_sequence_for<Ts...>{});
}
int main()
{
    int x{};
    std::variantzint, doube, float> v = 1;

    fmt::printl("{}", has_type<int>(v));

    
    CALL_VALUE_CATG(x);
}