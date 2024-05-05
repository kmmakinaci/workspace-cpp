# Understanding Callable Types in C++

## Introduction
In C++, callable types provide a versatile mechanism for defining and using functions. In other words, a callable term generally refers to anything that can be called like a function. Essentially, any entity that can be invoked with parentheses and arguments is considered callable.

## Objective
- The concept of callable types in C++
- Various constructs for defining callable objects
- Differences between lambdas and std::function
- Practical scenarios for using callable types

## Callable Types
In C++, callable types refer to entities that can be invoked as functions. These include regular functions,
function pointers, function objects (functors), and lambdas.

### Regular Functions
Regular functions are the standard way of defining reusable blocks of code with a specific name and signature.
CPPWeekly/HowToLambdavsFunction.cpp#L11

### Function Pointers
Funtion pointers are pointers that point to funtions. They provide flexibility in dynamically selecting and invoking functions at runtime.
```
int (*ptr)(int, int) = add;
int result = ptr(3, 4);
```

### Function Objects(Functors)
Function objects are objects that behave like functions. They overload the function call operator `operator()` to enable instances to be invoked as functions.
CPPWeekly/HowToLambdavsFunction.cpp#L1
&
```
struct Add {
    int operator()(int x, int y) const {
        return x + y;
    }
};
Add add_functor;
int result = add_functor(3, 4);
```

### Lambdas
Lambdas are anonymous functions introduced in C++11.
They provide a concose way of defining inline functions, often used for short, one-off tasks.
CPPWeekly/HowToLambdavsFunction.cpp#L29

###  Differences between Lambdas and std::function
While lambdas and std::function both represent callable objects, they differ in their implementation and usage. Lambdas are lightweight and can capture variables from their enclosing scope, while std::function provides a type-erased wrapper around any callable target, including regular functions, function pointers, and function objects.

### Practical Examples
Callable types find various applications in C++ programming, such as:
*Callback mechanisms
*Implementing polymorphic behavior
*Functional programming paradigms
*Asynchronous programming