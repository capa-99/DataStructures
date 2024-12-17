//Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure. It can be seen as an optimization over selection sort where we first find the max (or min) element and swap it with the last (or first). We repeat the same process for the remaining elements. In Heap Sort, we use Binary Heap so that we can quickly find and move the max element in O(Log n) instead of O(n) and hence achieve the O(n Log n) time complexity.

//Heap Sort Algorithm
//Convert the array into a max heap using heapify, which happens in-place. The array elements are re-arranged to follow heap properties. One by one delete the root node of the Max-heap and replace it with the last node and heapify. Repeat this process while size of heap is greater than 1.
//Rearrange array elements so that they form a Max Heap.
//Repeat the following steps until the heap contains only one element:
//Swap the root element of the heap (the largest element) with the last element of the heap.
//Remove the last element of the heap by reducing heap size 
//Heapify the remaining elements of the heap.
//The array is sorted

//Detailed Working of Heap Sort
//Step 1: Treat the Array as a Complete Binary Tree
//Visualize the array as a complete binary tree. For an array of size n, the root is at index 0, the left child of an element at index i is at 2i + 1, and the right child is at 2i + 2.
//Step 2: Build a Max Heap
//Step 3: Sort the array by placing largest element at end of unsorted array.
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i) 
    {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) 
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}

//Complexity Analysis of Heap Sort
//Time Complexity: O(n log n)
//Auxiliary Space: O(log n). It can be O(1) for iterative implementation.

//Important points about Heap Sort
//In-place algorithm.
//it's not stable but can be made stable
//2-3 times slower than QuickSort because of a lack of locality of reference.

//Advantages of Heap Sort
//Efficient Time Complexity: O(n log n) in all cases so it's efficient for sorting large datasets. The log n factor comes from the height of the binary heap
//Memory Usage:  minimal if heapify() is written iteratively
//Simplicity: simpler to understand 

//Disadvantages of Heap Sort
//Costly: constants are higher so it's more costly than merge sort
//Unstable 
//Inefficient