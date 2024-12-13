//QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

//How does QuickSort Algorithm work?
//It works on the principle of divide and conquer, breaking down the problem into smaller sub-problems.
//Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (first, last, random element, median...).
//Partition the Array: Rearrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot on its right. The pivot is then in its correct position, and we obtain its index.
//Recursively Call: Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).
//Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.

//Choice of Pivot
//Always pick the first or last element as a pivot. The problem with this approach is it ends up in the worst case when array is already sorted.
//Pick a random element as a pivot. This is a preferred approach because it does not have a pattern for which the worst case happens.
//Pick the median element is pivot. This is an ideal approach in terms of time complexity as we can find median in linear time and the partition function will always divide the input array into two halves, but it takes more time on average.

//Partition Algorithm
//The key process in quickSort is a partition(). All these algorithms have O(n) time complexity.
//Naive Partition: Create copy of the array. Put all smaller and greater elements. Copy the temporary array back to original array. This requires O(n) extra space.
//Lomuto Partition: Keep track of index of smaller elements and keep swapping. 
//Hoare’s Partition: The fastest. Traverse the array from both sides and keep swapping greater element on left with smaller on right while the array is not partitioned.

//Working of Partition Algorithm with Illustration
//Start from the leftmost element and keep track of the index of smaller or equal elements as i . While traversing, if we find a smaller element, swap the current element with arr[i]. Otherwise, ignore the current element. 

//Illustration of QuickSort Algorithm
//Apply the same method recursively to the smaller sub-arrays on the left and right of the pivot. Each time, select new pivots and partition the arrays again. This process continues until only one element is left, which is always sorted. Once every element is in its correct position, the entire array is sorted.
//Quick Sort is a crucial algorithm in the industry, but there are other sorting algorithms that may be more optimal.
void quickRecursive(int *arr, int beg, int end)
{
    if(beg >= end)
    {
        return;
    }
    int pivot = arr[end];
    int *tmp = new int[end-beg+1];
    int lessPtr = 0, greaterPtr = end - beg;
    for(int i = beg; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            tmp[lessPtr] = arr[i];
            lessPtr++;
        }
        else
        {
            tmp[greaterPtr] = arr[i];
            greaterPtr--;
        }
    }
    tmp[lessPtr] = pivot;
    int j = 0;
    for(int i = beg; i <= end; i++)
    {
        arr[i] = tmp[j];
        j++;
    }
    delete tmp;
    quickRecursive(arr, beg, lessPtr + beg - 1);
    quickRecursive(arr, greaterPtr + beg + 1, end);
}
void quickSort(int *arr, int n)
{
    quickRecursive(arr, 0, n-1);
}

//Complexity Analysis of Quick Sort
//Time Complexity:
//Best Case: (O(n log n)), Occurs when the pivot element divides the array into two equal halves.
//Average Case (O(n log n)), On average, the pivot divides the array into two parts, but not necessarily equal.
//Worst Case: (O(n²)), Occurs when the smallest or largest element is always chosen as the pivot.
//Auxiliary Space: O(n), due to recursive call stack

//Advantages of Quick Sort
//Divide-and-conquer algorithm that makes it easier to solve problems.
//Efficient on large data sets.
//Low overhead, as it requires a small amount of memory to function.
//Cache Friendly
//Fastest general purpose algorithm for large data when stability is not required.
//Tail recursive so all tail call optimization can be done.

//Disadvantages of Quick Sort
//Worst-case time complexity of O(n²), which occurs when the pivot is chosen poorly.
//Not a good choice for small data sets.
//Not a stable sort, the relative order is not preserved.
