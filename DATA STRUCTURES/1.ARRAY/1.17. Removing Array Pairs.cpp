//Given an array of n integers, reduce the size of array to one by selecting a pair of integers and removing the larger one of two. Cost of this operation is equal to value of smaller one. Find out minimum sum of costs of operations needed to convert the array into a single element.
//Always pick the minimum value as part of the pair and remove larger value. This minimizes the cost 
#include <climits>
int costOfRemoving(int *arr, int n)
{
    int min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return (n - 1) * min;
}
//Time Complexity: O(n), min function costs O(n)
//Auxiliary Space: O(1), no extra space used