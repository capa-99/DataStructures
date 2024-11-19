//Given an array arr[], the task is to find the subarray that has the maximum sum and return its sum

#include <iostream> 
#include <climits>
using namespace std;

struct int_array
{
    int* arr;
    int n;
};

void print(int_array* a)
{
    for(int i = 0; i < a->n; i++)
    {
        cout << a->arr[i] << " ";
    }
}

//O(n²) time and O(1) space
//The idea is to run two nested loops to iterate over all possible subarrays and find the maximum sum
//The outer loop will mark the starting point of a subarray and inner loop will mark the ending point of the subarray
int maxSubarraySumByIteratingOverAllSubarrays(int_array* a)
{
    int max = INT_MIN;
    for(int i = 0; i < a->n; i++)
    {
        int sum = 0;
        for(int j = i; j < a->n; j++)
        {
            sum = sum + a->arr[j];
            if(sum > max)
            {
                max = sum;
            }
        }
    }
    return max;
}

//The idea of Kadane's algorithm is to traverse over the array from left to right and for each element, find the maximum sum among all subarrays ending at that element
//The result will be the maximum of all these values
//To calculate the maximum sum of subarray ending at current element, say maxEnding, use the maximum sum ending at the previous element, so for any element there are two choices
//Choice 1: Extend the maximum sum subarray ending at the previous element by adding the current element to it
//If the maximum subarray sum ending at the prvious index is positive, it's always better to extend the subarray
//Choice 2: Start a new subarray starting from the current element
//If the maximum subarray sum ending at the previous index is negative, it is always better to start a new subarray from the current element
//This means that maxEnding at index i = max(maxEnding at index (i - 1) + arr[i], arr[j]) and the maximum value of maxEnding at any index will be our answer
int maxSubarraySumUsingKadanesAlgorithm(int_array* a)
{
    int max = a->arr[0];
    int maxEnding = max;
    for(int i = 1; i < a->n; i++)
    {
        maxEnding = maxEnding + a->arr[i];
        if(maxEnding < a->arr[i])
        {
            maxEnding = a->arr[i];
        }
        if(maxEnding > max)
        {
            max = maxEnding;
        }
    }
    return max;
}
//Time complexity: O(n), since the array is traversed once
//Auxiliary space: O(1)

int main()
{
    int_array numbers;
    numbers.n = 5;
    numbers.arr = new int[15];
    numbers.arr[0] = -1;
    numbers.arr[1] = 8;
    numbers.arr[2] = -4;
    numbers.arr[3] = 7;
    numbers.arr[4] = -1;
    
    int res = maxSubarraySumByIteratingOverAllSubarrays(&numbers);
    res = maxSubarraySumUsingKadanesAlgorithm(&numbers);

    print(&numbers);
    cout << res;

    return 0;
}