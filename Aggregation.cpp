/*
Let us try to illustrate the implementation of the aggregation type of relation between 2 classes;
 Person and Address

Aggregation is a type of association where one class is a part of another class. 
It represents a "has-a" relationship. In this example, a Person "has an" Address.

UML Class Diagram:
------------------
+----------------+        +----------------+
|    Person      |        |    Address     |
+----------------+        +----------------+
| - name: string |<>------| - houseNo: int |
| - address:     |        | - colony: string|
|   shared_ptr   |        | - city: string |
|   <Address>    |        | - state: string|
+----------------+        +----------------+
| + getName():   |        | + getHouseNo():|
|   string       |        |   int          |
| + getAddress():|        | + getColony(): |
|   shared_ptr   |        |   string       |
|   <Address>    |        | + getCity():   |
| + setAddress(  |        |   string       |
|   shared_ptr   |        | + getState():  |
|   <Address>):  |        |   string       |
|   void         |        +----------------+
| + display():   |
|   void         |
+----------------+
*/

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Address {
public:
    int houseNo;
    string colony, city, state;
    
    Address(int hno, const string& colony, const string& city, const string& state)
        : houseNo(hno), colony(colony), city(city), state(state) {}

    int getHouseNo() const { return houseNo; }
    string getColony() const { return colony; }
    string getCity() const { return city; }
    string getState() const { return state; }
};

class Person {
private:
    string name;
    shared_ptr<Address> address;
public:
    Person(const string& name, shared_ptr<Address> address)
        : name(name), address(address) {}

    string getName() const { return name; }
    shared_ptr<Address> getAddress() const { return address; }

    void setAddress(shared_ptr<Address> newAddress) {
        address = newAddress;
    }

    void display() const {
        cout << name << " " << address->houseNo << " " << address->colony << " " << address->city << " " << address->state << endl;
    }
};

int main() {
    auto add1 = make_shared<Address>(868, "Mahavir Colony", "Jahagirpuri", "New Delhi");
    auto add2 = make_shared<Address>(123, "Green Park", "South Delhi", "New Delhi");

    Person p1("Raj", add1);
    Person p2("Seema", add1);

    p1.display();
    p2.display();

    // Update address for p1
    p1.setAddress(add2);
    p1.display();
    
    return 0;
}
