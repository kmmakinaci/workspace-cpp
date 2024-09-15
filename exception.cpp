#include <stdio.h>


/*
Throwing exception:
    * Memory for the exceptıon object ıs allocated in an unspecıfıed way
    * Seperate stack unwinding mechanism
Cathing exceptions:
    * Exception handler is from a point previously passed by execution
    * Use RTTI to do polymorphic catching of exceptions

Exception hygiene
    * Thwo by value
    * Catch by(const) referene
    * Rethrow using throw with no arguments
    * Catch handlers with derived classes
           before catch handlers with base classes

Exception safety:
    * No-throw guarantee
    * Basic guarantee
    * Strong guarantee

Exceptions can leave the function at any time resulting a leak
Use RAII over catch handlers for resource management
*/
enum MyStatus {good, not_good, bad};

//Thwrows MyStatus on error
void apply(MyClass& out);

int main(){
    bool stay_active = true;
    while(stay_active){
        try{//happy path
            MyClass me{"Kemal",22};
            appyly(me);            
        }catch(const MyStatus& s){//error handling
            std::cout<<"error : "<<s<<std::endl;
        }catch(...){//exception swallower
            std::cout<<"Unknown error:"<<std::endl;
        }

    }
} 