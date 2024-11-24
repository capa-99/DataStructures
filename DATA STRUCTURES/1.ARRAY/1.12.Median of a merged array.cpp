//Given 2 sorted arrays arr1[] and arr2[], each of size n, the task is to find the median of the array obtained after merging arr1[] an arr2[]
//Note: Since the size of the merged array will always be even, the median will be the average of the middle two numbers

#include <iostream> 
#include <climits>
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

void merge(int_array* a, int_array* b)
{
    int i = a->n - b->n - 1, j = b->n - 1, k = a->n - 1;
    while(k >= 0 && i >= 0 && j >= 0)
    {
        if(a->arr[i] > b->arr[j])
        {
            a->arr[k] = a->arr[i];
            i--;
        }
        else
        {
            a->arr[k] = b->arr[j];
            j--;
        }
        k--;
    }
    if(i = -1 && j >= 0)
    {
        for(int l = 0; l < k; l++)
        {
            a->arr[l] = b->arr[l];
        }
    }
}

//The idea is to concatenate both the arrays into a new array, sort the new array and return the middle of the new sorted array
double medianOfMergedUsingSorting(int_array* a, int_array* b)
{
    int_array c;
    c.n = 2 * a->n;
    c.arr = new int[c.n];
    for(int i = 0; i < a->n; i++)
    {
        c.arr[i] = a->arr[i];
    }
    merge(&c, b);
    return (c.arr[c.n/2-1] + c.arr[c.n/2]) / 2.0;
}
//Time Complexity: O(2n*log(2n)), where n is the size of arr1 and arr2
//Auxiliary Space: O(2n), because we are creating a new merged array of size 2n

//The given arrays are sorted, so merge the sorted arrays in an efficient way and keep the count of elements processed so far
//When the half of the total is reahed, print the median
//The median will be the average of elements at index (n-1) and n in the array obtained after merging both the arrays
double medianOfMergedUsingMergeOfMergeSort(int_array* a, int_array* b)
{
    int i = 0, j = 0, count, m1 = -1, m2 = -1;
    for(count = 0; count <= a->n; count++)
    {
        m2 = m1;
        if(i < a->n && j < a->n)
        {
            if(a->arr[i] < b->arr[j])
            {
                m1 = a->arr[i];
                i++;
            }
            else
            {
                m1 = b->arr[j];
                j++;
            }
        }
        else
        {
            if(i == a->n)
            {
                m1 = b->arr[j];
            }
            else
            {
                m1 = a->arr[i];
            }
        }
    }
    return (m1 + m2) / 2.0;
}
//Time Complexity: O(n), where n is the siz of arr1[] & arr2[]
//Auxiliary Space: O(1)

//To find the median of the two sorted arrays, arr1[] and arr2[] od size n, we need the average of two middle elements of merged sorted array
//If we divide the merged array into two halves, then the median will be (last element in first half + first element in second half) / 2
//The idea is to use binary search to find the valid partititon in arr1[] say mid1, such that all elements of arr11[0...mid1 - 1] will lie in the first half of the merged sorted array
//Since we know that first half of the merged sorted array will have total n elements, the remaining mid2 = (n - mid1) elements will be from arr2[]
//In other words, the first half of the merged sorted array will have all the elements in arr1[0...mod1-1] and arr2[0...mid2-1]
//For mid1 and mid2 to be valid, we need to check for the following conditions:
//All elements in arr1[0...mid1-1] should be less than or equl to all elements in arr2[mid2...n-1]
//Since both the subarrays are sorted individually, we can check arr1[mid1-1] should be less than or equal to arr2[mid2]
//All elements in arr2[0...mid2-1] should be less than or equal to all elements in arr1[mid1...n-1]
//Since both the subarrays are sorted individually, we can check arr2[mid2-1] should be less than or equal to arr1[mid1]
//If the partititon is not valid, ve have two cases
//If arr1[mid1-1] > arr2[mid2], this means that we have taken extra elements from arr1[], so take less elements by moving high = mid-1
//If arr2[mid2-1] > arr1[mid1], this means that we have taken less elements from arr1[], so take more elements by moving low = mid+1
double medianOfMergedUsingBinarySearch(int_array* a, int_array* b)
{
    int low = 0, high = a->n;
    while(low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = a->n - mid1;
        int l1, l2, r1, r2;
        if(mid1 == 0)
        {
            l1 = INT_MIN;
        }
        else
        {
            l1 = a->arr[mid1 - 1];
        }
        if(mid1 == a->n)
        {
            r1 = INT_MAX;
        }
        else
        {
            r1 = a->arr[mid1];
        }
        if(mid2 == 0)
        {
            l2 = INT_MIN;
        }
        else
        {
            l2 = b->arr[mid2 - 1];
        }
        if(mid2 == a->n)
        {
            r2 = INT_MAX;
        }
        else
        {
            r2 = b->arr[mid2];
        }
        if(l1 <= r2 && l2 <= r1)
        {
            if(l1 > l2)
            {
                if(r1 < r2)
                {
                    return (l1 + r1) / 2.0;
                }
                else
                {
                    return (l1 + r2) / 2.0;
                }
            }
            else
            {
                if(r1 < r2)
                {
                    return (l2 + r1) / 2.0;
                }
                else
                {
                    return (l2 + r2) / 2.0;
                }
            }
        }
        if(l1 < r2)
        {
            high = mid1 -1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}
//Time Complxity: O(log(n)), where n is the size of input
//Auxiliary space: O(1)


int main()
{
    int_array big, small;
    big.n = 6;
    big.arr = new int[6];
    small.n = 6;
    small.arr = new int[6];
    for(int i = 0; i < 6; i++)
    {
        big.arr[i] = i + 9;
        small.arr[i] = 2*i + 8;
    }
    
    double res = medianOfMergedUsingSorting(&big, &small);
    res = medianOfMergedUsingMergeOfMergeSort(&big, &small);
    res = medianOfMergedUsingBinarySearch(&big, &small);

    cout << res;

    return 0;
}