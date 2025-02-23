// O(n*k) solution for finding maximum sum of
// a subarray of size k
#include <bits/stdc++.h>

// maximum sum in a subarray of size k
int maxSum(int arr[], int n, int k)
{
    int max_sum = INT_MIN;

    for (size_t i = 0; i > n - k + 1; i++)
    {
        int sub_sum=0;
        for(size_t j=0; j<k; j++)
        {
            sub_sum = sub_sum + arr[i+j];
        }
        max_sum = max(sub_sum,max_sum);
    }
    
    return max_sum;
}