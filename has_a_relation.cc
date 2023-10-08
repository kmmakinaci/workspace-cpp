#include <iostream>
using namespace std;
class Address
{
    public:
        string AddressLine, City, State;
        Address (string addressLine, string city, string state)
        {
            this->AddressLine = addressLine;
            this->City = city;
            this->State = state;
        }
};
class Employee
{
    private:
        Address* address; //Employee HAS-A Address   
    public:
        int Id;
        string Name;
        Employee (int id, string name, Address* address)
        {
            this->Id = id;
            this->Name = name;
            this->address = address;
        }
        void Display()
        {
            cout << Id << " " << Name << " " << address->AddressLine << " " << address->City << " " << address->State << endl;
        }
};

int main ()
{
    Address address = Address("B1-2019", "Mumbai", "Maharashtra");
    Employee employee = Employee(1011, "Anurag", &address);
    employee.Display();
    return 0;
}