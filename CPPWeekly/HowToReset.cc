#include <memory>
#include <any>

std::unique_ptr<std::any> get_value();

int main()
{
    auto value = get_value();
    value.reset(); //reset the pointer
    value->reset(); //reset the pointed-to thing

    /*BEWARE
    Which one did you mean to do?
    If you have a container like thing with an - interface
    that contains a twith a similar interface

    No static analysis for this!!
    */
    return value == nullptr;
}