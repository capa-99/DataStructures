//Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. 

//Start with second element of the array as first element is assumed to be sorted.
//Compare second element with the first element and check if the second element is smaller then swap them.
//Move to the third element and compare it with the first two and put at its correct position
//Repeat until the entire array is sorted.
void insertionSort(int *arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        while(arr[i] < arr[j])
        {
            j--;
        }
        int tmp = arr[i];
        for(int k = i - 1; k > j; k--)
        {
            arr[k+1] = arr[k];
        }
        arr[j+1] = tmp;
    }
}

//Complexity Analysis of Insertion Sort :
//Time Complexity of Insertion Sort
//Best case: O(n) , If the list is already sorted, where n is the number of elements in the list.
//Average case: O(n 2 ) , If the list is randomly ordered
//Worst case: O(n 2 ) , If the list is in reverse order
//Space Complexity of Insertion Sort
//Auxiliary Space: O(1), making it a space-efficient sorting algorithm.

//Advantages of Insertion Sort:
//Simple and easy to implement.
//Stable sorting algorithm.
//Efficient for small lists and nearly sorted lists.
//Space-efficient as it is an in-place algorithm.
//Adoptive. the number of inversions is directly proportional to number of swaps.

//Disadvantages of Insertion Sort:
//Inefficient for large lists.
//Not as efficient as other sorting algorithms (merge, quick) for most cases.

//Applications of Insertion Sort:
//The list is small or nearly sorted.
//Simplicity and stability are important.
//Used as a subroutine in Bucket Sort
//Can be useful when array is already almost sorted
//Used in Hybrid Sorting algorithms 