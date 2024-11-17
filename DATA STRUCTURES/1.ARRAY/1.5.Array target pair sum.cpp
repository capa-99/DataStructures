//Given an array arr[] of n integers and a target value, find whether there is a pair of elements in the array whose sum is equal to target
//a variation of 2Sum problem

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 
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

//Generate all the possible pairs and check if any of them adds up to the target value by running two neted loops
bool findTargetPairByGeneratingAllPossiblePairs(int_array* a, int target)
{
    for(int i = 0; i < a->n; i++)
    {
        for(int j = i + 1; j < a->n; j++)
        {
            if(a->arr[i] + a->arr[j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
//Time complexity: O(n²) for uing two ested loops
//Auxiliary space: O(1)

//First sort the array because searching in sorted array takes O(n*log(n)) time
//For each number in the array calculate its complement (target - that number) then use binary search to check if this complement exists in the subarray after index i
//If the omplement is found return true, but if it's never found return false (after checking all numbers)
bool findTargetBySortingAndBinarySearch(int_array* a, int target)
{
    vector<int> temp;
    for(int i = 0; i <a->n; i++)
    {
        temp.push_back(a->arr[i]);
    }
    sort(temp.begin(), temp.end());
     for(int i = 0; i <a->n; i++)
    {
        a->arr[i] = temp[i];
    }
    
    for(int i = 0; i < temp.size(); i++)
    {
        int complement = target - a->arr[i];
        int check = binarySearch(a, complement, i + 1, a->n - 1);
        if(check != -1)
        {
            return true;
        }
    }
    return false;
}
//time complexity: O(n*log(n)) for sorting the array
//Auxiliary space: O(1)

//The array must be sorted
//Use two-pointer technique by keeping one pointer at the beginning (left) and another a the end (right) of the array
//Check the sum of the elements of these two pointers
//If the sum equals the target the pair is found
//If the sum is less than the target, move the left pointer to the right to inrease the sum
//If the sum is greater than the target, move the right pointer to the left to decrease the sum
bool findTargetWithSortingAndTwoPointerTechnique(int_array* a, int target)
{
    vector<int> temp;
    for(int i = 0; i <a->n; i++)
    {
        temp.push_back(a->arr[i]);
    }
    sort(temp.begin(), temp.end());
     for(int i = 0; i <a->n; i++)
    {
        a->arr[i] = temp[i];
    }

    int left = 0, right = a->n - 1;
    while(left < right)
    {
        if((a->arr[left] + a->arr[right]) == target)
        {
            return true;
        }
        else if((a->arr[left] + a->arr[right]) < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}
//Time complexity: O(n*log(n)), for sorthing the array
//Auxiliary space:O(1)

//Best for non sorted array
//Rather than checking every possible pair, each number is stored in an unsorted setduring iterating over the array's elements
//For each number calculate the complement (target - curent number) and check if it exists in the set
//If it exists, the pair that sums to the target is found
//linear time solving, O(n)
bool findTargetUsingHashSet(int_array* a, int target)
{
    unordered_set<int> hash;
    for(int i = 0; i < a->n; i++)
    {
        int complement = target - a->arr[i];
        if(hash.find(complement) != hash.end())
        {
            return true;
        }
        hash.insert(a->arr[i]);
    }
    return false;
}
//Time complexity: O(n), for single iteration over the array
//Auxiliary space O(n), for hashmap

int main()
{
    int_array numbers;
    numbers.n = 5;
    numbers.arr = new int[15];
    numbers.arr[0] = 1;
    numbers.arr[1] = 8;
    numbers.arr[2] = 2;
    numbers.arr[3] = 0;
    numbers.arr[4] = 7;
    int target = 10;
    
    bool result = findTargetPairByGeneratingAllPossiblePairs(&numbers, target);
    result = findTargetBySortingAndBinarySearch(&numbers, target);
    result = findTargetWithSortingAndTwoPointerTechnique(&numbers, target);

    print(&numbers);
    cout << result;

    return 0;
}