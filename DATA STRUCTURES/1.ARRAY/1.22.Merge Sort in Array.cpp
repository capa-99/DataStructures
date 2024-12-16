//Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array.

//How does Merge Sort work?
//It follows the divide-and-conquer approach to sort the array.
//Divide: Divide the list or array recursively into two halves until it can no more be divided.
//Conquer: Each subarray is sorted individually using the merge sort algorithm.
//Merge: The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.
void merge(int *arr, int beg, int end)
{
    if(beg >= end)
    {
        return;
    }
    int mid = beg + (end - beg) / 2;
    merge(arr, beg, mid);
    merge(arr, mid + 1, end);
    int *a = new int[mid-beg+1];
    int *b = new int[end-mid];
    for(int i = 0; i < mid-beg+1; i++)
    {
        a[i] = arr[i+beg];
    }
    for(int i = 0; i < end-mid; i++)
    {
        b[i] = arr[i+mid+1];
    }
    int i = 0, j = 0, k = beg;
    while(i < mid-beg+1 && j < end-mid)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < mid-beg+1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < end-mid)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void mergeSort(int *arr, int n)
{
    merge(arr, 0, n-1);
}

//Recurrence Relation of Merge Sort:
//T(n) = { O(1) if n = 1
//       { 2T(n/2)+O(n) if n > 1
//T(n) represents the total time taken by the algorithm to sort an array of size n.
//2T(n/2) represents time taken by the algorithm to recursively sort the two halves of the array. Since each half has n/2 elements, we have two recursive calls with input size as (n/2).
//O(n) represents the time taken to merge the two sorted halves

//Complexity Analysis of Merge Sort:
//Time Complexity:
//Best Case: O(n log n), already or nearly sorted.
//Average Case: O(n log n), randomly ordered.
//Worst Case: O(n log n), sorted in reverse order.
//Auxiliary Space: O(n), Additional space is required for the temporary array used during merging.

//Applications of Merge Sort:
//Sorting large datasets
//External sorting (when the dataset is too large to fit in memory)
//Inversion counting
//Library methods of programming languages
//Linked lists sorting
//Easily parallelized
//Efficient for problems like union and intersection of two sorted arrays

//Advantages of Merge Sort:
//Stability : It maintains the relative order of equal elements in the input array.
//Guaranteed worst-case performance: worst-case time complexity of O(N logN) , which means it performs well even on large datasets.
//Simple to implement: The divide-and-conquer approach is straightforward.
//Naturally Parallel : Suitable for parallel processing.

//Disadvantages of Merge Sort:
//Space complexity: requires additional memory during the sorting process.
//Not in-place: because of additional memory
//Slower than QuickSort in general.