// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iterator>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // Implement your solution here
    std::stack<int> stack;

    //put string content into vector ds
    std::istringstream iss(S);
    std::vector<std::string> ops {
        std::istream_iterator<std::string>{iss},
        std::istream_iterator<std::string>{}
    };

    //find operation or value
    for (const std::string& op : ops){
        if(op == "POP"){
            if (stack.empty())
                return -1;
            stack.pop();
        }
        else if(op == "DUP"){
            if (stack.empty())
                return -1;
            stack.push(stack.top());
        }
        else if(op == "+")
        {
            if(stack.size()<3)
                return -1;
            int val1 = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();
            int val = val1 + val2;
            stack.push(val);
        }
        else if(op == "-")
        {
            if(stack.size()<3)
                return -1;
            int val1 = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();
            int val = val2 - val1;
            if (val < 0)
                return -1;
            stack.push(val);
        }
        else{
            int val = std::stoi(op);
            if(val < 0)
                return -1;
            stack.push(val);
        }
    }

    if (stack.empty())
        return -1;

    return stack.top();

}
