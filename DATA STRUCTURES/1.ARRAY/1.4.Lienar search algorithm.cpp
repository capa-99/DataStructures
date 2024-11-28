//Given an array arr of n integers, and an integer element x, find whether element x is present in the array. Return the index of the first occurrence of x in the arrayy, or -1 if it doesn't exist
//In Linear Search, we iterate over all the elements of the array and check if the current element is equal to the target element. If we find it, return the index of the current element. Otherwise, return -1. Linear search is also known as sequetial search
int linearSearch(int* arr, int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

//Time and Space Complexity of Linear Search Algorithm:
//Time Complexity:
//Best Case: The key might be present at the first index, so the complexity is O(1)
//Worst Case: The key might be present at the last index, so the complexity is O(N) where N is the size of the list.
//Average Case: O(N)
//Auxiliary Space: O(1), except an iterator, no other variables used

//Applications of Linear Search Algorithm:
//Unsorted Lists: When we have an unsorted array or list, linear search is most commonly used to find any element in the collection.
//Small Data Sets: Linear Search is preferred over binary search when we have small data sets
//Searching Linked Lists: In linked lists, linear search is commonly used to find elements within the list. Each node is checked sequentially until the desired element is found.
//Simple Implementation: Linear Search is much easier to understand and implement as compared to Binary or Ternary Search.

//Advantages of Linear Search Algorithm:
//It can be used irrespective of whether the array is sorted or not an it can be used on arrays of any data type.
//It does not require any additional memory.
//It is a well-suited algorithm for small datasets.

//Disadvantages of Linear Search Algorithm:
//Slow for large datasets because of its O(N) time complexity
//Not suitable for large arrays.

//When to use Linear Search Algorithm?
//When dealing with a small dataset.
//When searching for a dataset stored in contiguous memory.