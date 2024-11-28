//Given an array arr[]of size n, the task is to find the largest element in the given array

//Iterative Approach – O(n) Time and O(1) Space
//Traverse the whole array and find the maximum among them.
//Create a local variable max and initiate it to arr[0] to store the maximum among the list
//Iterate over the array
//Compare arr[i] with max.
//If arr[i] > max, update max = arr[i].
//Increment i once.
//After the iteration is over, return max as the requierd answer
int largestElementIterativeApproach(int* arr, int n)
{
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

//Recursive Approach – O(n) Time and O(n) Space
//The idea is similar to the iterative approach except the traversal of the array is done recursively instead of an iterative loop. 
//Set an integer i = 0 to denote the current index being searched.
//Check if i is the last index, return arr[i].
//Increment i and call the recursive function for the new value of i.
//Compare the maximum value returned from the recursion function with arr[i].
//Return the max between these two from the current recursion call.
int maximum(int* arr, int n, int i, int max)
{
    if(i == n - 1)
    {
        if(arr[i] > max)
        {
            return arr[i];
        }
        else
        {
            return  max;
        }
    }
    if(arr[i] > max)
    {
        return maximum(arr, n, i + 1, arr[i]);
    }
    else
    {
        return maximum(arr, n, i + 1, max);
    }
}

int largestElementRecursiveApproach(int *arr, int n)
{
    return maximum(arr, n, 0, -1);
}

//Using Library Methods
//Most of the languages have a relevant max() type in-built function to find the maximum element. Use this funtion to directly find the maximum element
#include <vector>
#include <algorithm>
using namespace std;

int largestElementUsingLibraryMethods(vector<int>& arr)
{
    return *max_element(arr.begin(), arr.end());
}