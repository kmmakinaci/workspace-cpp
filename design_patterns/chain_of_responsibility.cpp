#include <iostream>

class StringValidator
{
public:
    virtual ~StringValidator(){};
    virtual StringValidator *setNext(StringValidator *nextValidator) = 0;
    virtual std::string validate(std::string) = 0;
};

class BaseValidator : public StringValidator
{
protected:
    StringValidator *next = nullptr;

public:
    virtual ~BaseValidator() { delete next; };
    StringValidator *setNext(StringValidator *nextValidator) override
    {
        next = nextValidator;
        return nextValidator;
    }

    virtual std::string validate(std::string testString) override
    {
        if (this->next)
        {
            return this->next->validate(testString);
        }

        return "Success";
    }
};

class NotEmptyValidator : public BaseValidator{
public:
    NotEmptyValidator(){};
    std::string validate(std::string test_string){
        std::cout<<"Checking if empty..."<<std::endl;

        if(test_string.empty()){
            return "Please enter a string"
        }

        return BaseValidator::validate(test_string);
    }
};

//LengthValidator 

//RegexValidator

//Duplicate Validator
