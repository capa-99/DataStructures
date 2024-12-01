//Given a sorted array arr[] of size n, rearrange the array so that all distinct elements appear at the beginning in sorted order. Return the length of this distinct sorted subarray
//Note: The elements after the distinct ones can be in any order and hold any value as they don't affect the result

//Using Hash Set - Works for Unsorted Also - O(n) Time and O(n) Space
//Use a hash set or dictionary to store elements already processed
//Initialize index of result array as 0.
//Traverse through the input array. If an element is not in the hash set, put it at the result index and insert into the set.
#include <vector>
#include <unordered_set>
using namespace std;
int removeDuplicatesUsingHashSet(int* arr, int n)
{
    unordered_set<int> s;
    int index = 0;
    for(int i= 0; i < n; i++)
    {
        if (s.find(arr[i]) == s.end()) { 
            s.insert(arr[i]);  
            arr[index] = arr[i];
            index++;  
        }
    }
    return s.size();
}

//O(n) Time and O(1) Space
//Since the array is sorted, we don't need to maintain a hash set. All occurrences of an element would be consecutive, so we only need to check if the current element is the same as the previous element or not. 
//Start with idx = 1 (idx is going to hold the index of the next distinct item. Since there is nothing before the first item, we consider it as the first distinct item and begin idx with 1.
//Loop through the array for i = 0 to n-1.
//At each index i, if arr[i] is different from arr[i-1], assign arr[idx] = arr[i] and increment idx.
//After the loop, arr[] contains the unique elements in the first idx positions.
int removeDuplicates(int *arr, int n)
{
    int index = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[index] != arr[i])
        {
            index++;
            arr[index] = arr[i];
        }
    }
    return index+1;
}