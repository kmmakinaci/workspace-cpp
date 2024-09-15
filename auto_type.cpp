/**
 * @brief 
 * 
 * Daily bit(e) of C++ | auto type deduction
 * https://open.substack.com/pub/simontoth/p/daily-bite-of-c-auto-type-deduction?r=1gpzxv&utm_campaign=post&utm_medium=web
 * https://en.cppreference.com/w/cpp/language/template_argument_deduction
 * 
 * Type deduction rules when deducting the type for the auto specifier.
 * 
 * When using auto, the type deduction follows the rules for 
 *                                                      template type deduction.
 * One practical consequence of these rules is that auto will never deduce
 *                                                                  a reference.
 * Otherwise, to corner cases to remember are:
 *  * auto&& is alwazs deduced and, therefore, a universal/forwarding reference
 *                                              (unlike T&& inside a template)
 *  * the behaviour when using list initialization
 * 
 */

#include <initializer_list>
#include <type_traits>
#include <utility>

int x{};
const int z{};

//auto will ot deduce a reference
auto v1 = x;    //decltype(v1) == int


