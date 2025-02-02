/*
Objective: memory handling and basic data operation
Steps:
* Reverse the array in place
* Find the maximum and minimum
* Compute sum of all elements
Rules:
* Use pointers instead of indexed loops where possible.
* Optimize for cache efficiency (avoid unnecessary memory accesses).
* Measure execution time for large N
*/

#include <iostream>
#include <memory>
#include <algorithm> //for std::reverse
#include <numeric>
#include <limits>   //for min/max
#include <chrono>

int main() {
    constexpr int N = 10000000; //large dataset
    
    // Allocate memory using a smart pointer
    std::unique_ptr<int[]> data = std::make_unique<int[]>(N);

    // Initialize array with values 1 ti N using pinter arithmetics
    std::iota(data.get(), data.get()+N, 1);

    auto start = std::chrono::high_resolution_clock::now();

    //Reverse using two pointer approach cache friendly
    int* left = data.get();
    int* right = data.get() + N -1;
    while (left < right) {
        std::swap(*left++, *right--);
    }

    auto result = std::minmax_element(data.get(), data.get() + N);
    long long sum = std::accumulate(data.get(), data.get() + N, 0LL);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end -start;

    std::cout << "[Sequential] Min: " << *result.first 
          << ", Max: " << *result.second 
          << ", Sum: " << sum 
          << ", Time: " << elapsed.count() << " sec\n";

    return 0;
}