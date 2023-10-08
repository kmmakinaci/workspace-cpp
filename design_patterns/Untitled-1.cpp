
//Let us try to illustrate the implementation of the aggregation type of relation between 2 classes Person and address using a C++ program.


#include <iostream>
#include<string.h>
using namespace std;
class Address {
public:
inthouseNo;
string colony,city, state;
Address(inthno, string colony, string city, string state)
{ this->houseNo = hno;
this->colony=colony;
this->city = city;
this->state = state;
}
};

class Person
{
private:
Address* address;
public:
string name;
Person(string name, Address* address)
{
this->name = name;
this->address = address;
}
void display()
{
cout<< name<< " "<< " "<< address->houseNo<<" "<<address-> colony<<" " <<address->city<< " "<<address->state<<endl;
}
};
int main(void) {
Address add1= Address(868 ,"Mahavir Colony","Jahagirpuri","New Delhi");
Person p1 = Person("Raj",&add1);
Person p2 = Person("Seema",&add1);
p1.display();
p2.display();
return 0;
}
Output:

