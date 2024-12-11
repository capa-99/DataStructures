//Given an array of integers arr[], move all the zeros to the end of the array while maintaining the relative order of all non-zero elements.

//Using Temporary Array – O(n) Time and O(n) Space
//Create a temporary array of same size as the input array arr[]. 
//Copy all non-zero elements from arr[] to the temporary array. 
//Fill all the remaining positions in temporary array with 0.
//Copy all the elements from temporary array to arr[].
void moveZeroesUsingTemporaryArray(int *arr, int n)
{
    int *temp = new int[n];
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }
    for(int i = j; i < n; i++)
    {
        temp[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
//Time Complexity: O(n), ass we are traversing the array three times
//Auxiliary Space: O(n), as we are using temp[] array to move all zeroes

//Two Traversals – O(n) Time and O(1) Space
//Move all the zeros by traversing the array twice.
//First Traversal: Shift non-zero elements
//Traverse the array and maintain the count of non-zero elements. This count is initialized with 0 and keeps track of where the next non-zero element should be placed in the array.
//If the element is non-zero, place it at arr[count] and increment count by 1.
//After traversing all the elements, all non-zero elements will be shifted to the front while maintaining their original order.
//Second Traversal: Fill remaining positions with zeros
//After the first traversal,  count will store the index where the first zero should be placed.
//Iterate from count to the end of array and fill all indices with 0.
void moveZeroesTwoTraversals(int *arr, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        arr[count] = arr[i];
        if(arr[i] != 0)
        {
            count++;
        }
    }
    for(int i = count; i < n; i++)
    {
        arr[i] = 0;
    }
}
//Time Complexity: O(n), as we are traversing the array twice
//Auxiliary Space: O(1)

//One Traversal – O(n) Time and O(1) Space
//Similar to the previous approach, count tracks where the next non-zero element should be placed. On encountering a non-zero element, instead of directly placing the non-zero element at arr[count], we will swap them. This will ensure that if there is any zero present at arr[count], it is pushed towards the end of array and is not overwritten.
void moveZeroesOneTraversal(int *arr, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            int tmp = arr[count];
            arr[count] = arr[i];
            arr[i] = tmp;
            count++;
        }
    }
    for(int i = count; i < n; i++)
    {
        arr[i] = 0;
    }
}
//Time Complexity: O(n), as we are traversing an array once
//Auxiliary Space: O(1)

//Using Library Methods
//In C++, there is a method stable_parition() that we can directly use
#include <vector>
#include <algorithm>
void moveZeroesUsingLibraryMethods(vector<int> &arr)
{
    stable_partition(arr.begin(), arr.end(), [](int n) { return n != 0; });
}