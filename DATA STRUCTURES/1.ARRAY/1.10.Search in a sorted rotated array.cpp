//Given a sorted and rotated array arr[] of n distinct elements, find the idex of given key in the array, if it's not present, return -1

#include <iostream> 
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

int binarySearch(int_array* a, int element, int beg, int end)
{
    if(beg > end)
    {
        return -1;
    }
    int mid = (beg + end) / 2;
    if(a->arr[mid] == element)
    {
        return mid;
    }
    if(a->arr[mid] < element)
    {
        return binarySearch(a, element, mid + 1, end);
    }
    return binarySearch(a, element, beg, mid - 1);
}

int findPivot(int_array* a, int low, int high)
{
    while(low < high)
    {
        if(a->arr[low] <= a->arr[high])
        {
            return low;
        }
        int mid = (low + high) / 2;
        if(a->arr[mid] > a->arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

//Using linear search
//A simple approach is to iterate through the array and chek for each element, if it matches the target then return the index, otherwise, return -1
//Complexity: O(n) time and O(1) auxiliary space

//1) Find the pivot point (or index of the min element)
//2) Do Binary Search in a Sorted Subarray: once the pivot is found, we can easily divide the given array into two sorted subarrays using the index of the min
//If the given key is same as minimum, return
//If min index is 0, call binary search for the whole array
//Compare the given key with the first element, do binary search in the first subarray, else, in second
int searchKeyUsingTwoBinarySearches(int_array* a, int key)
{
    int pivot = findPivot(a, 0, a->n - 1);
    if(a->arr[pivot] == key)
    {
        return pivot;
    }
    if(pivot == 0)
    {
        return binarySearch(a, key, 0, a->n - 1);
    }
    if(a->arr[0] <= key)
    {
        return binarySearch(a, key, 0, pivot - 1);
    }
    return binarySearch(a, key, pivot + 1, a->n - 1);
}

//The idea is based on the fact that in a sorted and rotated array, if we go mid, then either the left half would be sorted, or the right (both can be sorted if the mid is the minimum or maximum element)
//We can check which half is sorted by comparing arr[low] and arr[mid] (or arr[mid] and arr[high])
//Find the mid point
//If key is same sa the mid, return mid
//Find which half is sorted
//If the key lies in the sorted half, move to thaat half
//Othewise move to other half
int searchKeyUsingOneBinarySearch(int_array* a, int key)
{
   int low = 0, high = a->n -1;
   while(low <= high)
   {
        int mid = low + (high - low) / 2;
        if(a->arr[mid] == key)
        {
            return mid;
        }
        if(a->arr[mid] >= a->arr[low])
        {
            if(key >= a->arr[low] && key < a->arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(key >= a->arr[mid] && key <= a->arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
   }
   return -1;
}
//Time comlexity: O(log(n))
//Auxiliary space: O(1)

int main()
{
    int_array numbers;
    numbers.n = 5;
    numbers.arr = new int[15];
    numbers.arr[0] = 1;
    numbers.arr[1] = 2;
    numbers.arr[2] = 3;
    numbers.arr[3] = 4;
    numbers.arr[4] = 0;
    
    int res = searchKeyUsingTwoBinarySearches(&numbers, 5);
    res = searchKeyUsingOneBinarySearch(&numbers, 5);

    print(&numbers);
    cout << res;

    return 0;
}