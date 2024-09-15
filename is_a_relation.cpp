#include <iostream>
using namespace std;

class Rectangle
{
    public:
        int length;
        int breadth;
        int Area()
        {
            return length * breadth;
        }
        int Perimeter ()
        {
            return 2 * (length + breadth);
        }
};

class Cuboid:public Rectangle
{
    public:
        int height;
        Cuboid(int l, int b, int h)
        {
            length = l;
            breadth = b;
            height = h;
        }
        int Volume ()
        {
            return length * breadth * height;
        }
};

int
main ()
{
  Cuboid c (2, 4, 6);
  cout << "Volume is " << c.Volume() << endl;
  cout << "Area is " << c.Area() << endl;
  cout << "Perimeter is " << c.Perimeter() << endl;
}