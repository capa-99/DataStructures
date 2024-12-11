//Given an array of n-elements, find the number of operations needed to make all elements of array equal, where a single operation can increment an element by k. If it is not possible to make all elements equal print -1.
//We need to check whether all elements can become equal or not and only by icrementing elements by k. Check if the difference of any two elements is divisible by k. If it is, all elements can become equal, otherwise, they can't. The number of operations required can be calculated by finding value of (max - A[i])/k for all elements where max is a maximum element in the array.
#include <climits>
int operationToEqual(int *arr, int n, int k)
{
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if ((max - arr[i]) % k != 0)
        {
            return -1;
        }
        res = res + (max - arr[i]) / k;
    }
    return res;
}
//Time Complexity: O(n)
//Auxiliary Space: O(1)