/*
Implement stack with array,
Due to array usage will not be dynamic. However easy to implement while pointers are not involved.
*/

#include <bits/stdc++.h>

#define MAX 1000

class Stack{
        int top;
public:
        int s[MAX];

        Stack() {top = -1;}
};
