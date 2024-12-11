//Given an array arr[], reverse it. Reversing an array means rearranging the elements such that the first element becomes the last, the second element becomes second last and so on

//Using a temporary array – O(n) Time and O(n) Space
//Use a temporary array to store the reverse of the array.
//Create a temporary array of same size as the original array. 
//Copy all elements from original array to the temporary array in reverse order.
//Copy all the elements from temporary array back to the original array.
void reverseUsingTemporaryArray(int* arr, int n)
{
    int* tmp = new int[n];
    for(int i = 0; i < n; i++)
    {
        tmp[i] = arr[n-i-1];
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = tmp[i];
    }
}
//Time Complexity: O(n), Copying elements to a new array is a linear operation.
//Auxiliary Space: O(n), as we are using an extra array

//Using Two Pointers – O(n) Time and O(1) Space
//Maintain two pointers: left and right, such that left points at the beginning of the array and right points to the end of the array. 
//While left pointer is less than the right pointer, swap the elements at these two positions. After each swap, increment the left pointer and decrement the right pointer. This will swap all the elements in the first half with their corresponding element in the second half.
void reverseUsingTwoPointers(int* arr, int n)
{
    int beg = 0, end = n - 1;
    while(beg < end)
    {
        int tmp = arr[end];
        arr[end] = arr[beg];
        arr[beg] = tmp;
        beg++;
        end--;
    }
}
//Time Complexity: O(n), as we are visiting each element once
//Auxiliary Space: O(1)

//By Swapping Elements – O(n) Time and O(1) Space
//Iterate over the first half of the array and swap each element with its corresponding element from the end. Any element at index i fom the first half is swapped with the element at index (n – i – 1).
void reverseBySwappingElements(int *arr, int n)
{
    for(int i = 0; i < n / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = tmp;
    }
}
//Time Complexity: O(n), the loop runs through half of the array, so it’s linear
//Auxiliary Space: O(1), no extra space is required, in-place reversing.

//Using Recursion – O(n) Time and O(n) Space
//Use recursion and define a recursive function that takes a range of array elements as input and reverses it. Inside the recursive function: 
//Swap the first and last element. 
//Recursively call the function with the remaining subarray. 
void reverse(int *arr, int beg, int end)
{
    if(beg >= end)
    {
        return;
    }
    int tmp = arr[beg];
    arr[beg] = arr[end];
    arr[end] = tmp;
    reverse(arr, beg+1, end-1);
}
void reverseUsingRecursion(int *arr, int n)
{
    reverse(arr, 0, n-1);
}
//Time Complexity: O(n), T(n) = T(n – 2) + O(1), which is simplified to O(n).
//Auxiliary Space: O(n), as we are using recursion stack.

//Using Inbuilt Methods - O(n) Time and O(1) Space
//Use inbuilt methods available
#include <vector>
#include <algorithm> 
using namespace std;
void reverseUsingInbulitMethods(vector<int> &arr)
{
    reverse(arr.begin(), arr.end());
}
//Time Complexity: O(n), linear complexity
//Auxiliary space: O(1), no additional space used