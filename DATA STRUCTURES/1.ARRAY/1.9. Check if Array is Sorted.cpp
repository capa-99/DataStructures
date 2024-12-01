//Given an array of size n, the task is to check if it is sorted in ascending order or not. Equal values are allowed in an array and two consecutive equal values are considered sorted.

//Iterative approach – O(n) Time and O(1) Space
//The benefit of the iterative approach is to avoids the usage of recursion stack space and recursion overhead. Logic is to iterate over the whole array and in every iteration check whether arr[i] > arr[i-1] or not.
bool isSortedIterativeApproach(int* arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1])
        {
            return false;
        }
    }
    return true;
}

//Recursive approach – O(n) Time and O(n) Space
//If size of array is zero or one, return true.
//Check last two elements of array, if they are sorted, perform a recursive call with n-1 else, return false.
bool isSortedRecursiveApproach(int* arr, int n)
{
    if(n < 2)
    {
        return true;
    }
    if(arr[n-1] < arr[n-2])
    {
        return false;
    }
    else
    {
        return isSortedIterativeApproach(arr, n-1);
    }
}
//Time Complexity: O(n)
//Auxiliary Space: O(n) for Recursion call stack
