#include <iostream>

class Base{
public:
  //virtual void foo()=0;//pure virtual //interface //abstract type
  virtual void foo(){
      std::cout << "Base::foo()\n";
  }  
};

class Der : public Base {
public:
    virtual void foo(){
        std::cout << "Der::foo()\n";
    }
    /*
    Abstract type concerete duruma gelir.
    void foo() override{
        std::cout << "Der::foo()\n";
    }
    */
};

int main(){
    Der d;
    d.foo();

    Base &rb = d;
    rb.foo();

//Sanal fonks,yon mekanizmaları girmediği yerler
    Base b = d; //object slicing
    //derleyici hata vermez, d'nin özellikleri kaybedilir.
    b.foo();
    b.Base::foo();// gösterilen sınıf fonksiyonu çağrılır.

}