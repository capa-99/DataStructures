//Given an array of positive integers arr[] of size n, find second largest distinct element in the array
//Note: If the second largest element dos not exist return -1

//Using Sorting - O(nlogn) Time and O(1) Space
//Sort the array in non-decreasing order. The largest element will be at index n – 1. Starting from index (n – 2), traverse the remaining array in reverse order. As soon as the element which is not equal to the largest element is encountered, return it as the second largest element. If all the elements are equal to the largest element, return -1.
#include <vector>
#include <algorithm>
using namespace std;
int secondLargestUsingSorting(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    for(int i = arr.size() - 2; i >= 0; i--)
    {
        if(arr[i] != arr[arr.size()-1])
        {
            return arr[i];
        }
    }
    return -1;
}
//Time Complexity: O(nlogn) as sorting the array takes O(nlogn) time and traversing can take O(n) time, in the worst case total time complexity is (nlogn + n) = O(nlogn)
//Auxiliary Space: O(1), as no extra space is required

//Two Pass Search - O(n) Time and O(1) Space
//Traverse the array twice. In the first traversal, find the maximum element. In the second traversal, find the maximum element ignoring the one we found in the first traversal
int secondLargestTwoPassSearch(vector<int>& arr)
{
    int max = -1, secMax = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == max - 1)
        {
            return arr[i];
        }
        if(arr[i] != max)
        {
            if(arr[i] > secMax)
            {
                secMax = arr[i];
            }
        }
    }
    return secMax;
}
//Time Complexity: O(2*n) = O(n)
//Auxiliary space: O(1), as no extra space is required.

//One Pass Search – O(n) Time and O(1) Space
//Keep track of the largest and second largest element while traversing the array. Initialize largest and second largest with -1. Now, for any index i,
//If arr[i] > largest, update second largest with largest and largest with arr[i].
//Else If arr[i] < largest and arr[i] > second largest, update second largest with arr[i]. 
int secondLargestOnePassSearch(vector<int>& arr)
{
    int max = -1, secMax = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > max)
        {
            secMax = max;
            max = arr[i];
        }
        else
        {
            if(arr[i] < max && arr[i] > secMax)
            {
                secMax = arr[i];
            }
        }
    }
    return secMax;
}
//Time Complexity: O(n), as we are traversing the array only once.
//Auxiliary space: O(1)