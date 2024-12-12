//Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.
//Find the smallest element and swap it with the first element. 
//Find the smallest among remaining elements and swap it with the second element.
//Keep doing this until all elements are moved to correct position.
void selectionSort(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

//Complexity Analysis of Selection Sort
//Time Complexity: O(n²) ,as there are two nested loops:
//One loop to select an element of Array one by one = O(n)
//Another loop to compare that element with every other Array element = O(n)
//Overall complexity = O(n) * O(n) = O(n*n) = O(n²)
//Auxiliary Space: O(1) as the only extra memory used is for temporary variables.

//Advantages of Selection Sort
//Easy to understand and implement.
//Requires only a constant O(1) extra memory space.
//Requires less number of swaps compared to many other standard algorithms. Therefore it can be simple algorithm choice when memory writes are costly.

//Disadvantages of the Selection Sort
//Time complexity of O(n²) makes it slower compared to algorithms like Quick or Merge Sort.
//Does not maintain the relative order of equal elements which means it is not stable.

//Applications of Selection Sort
//Teaching fundamental sorting mechanisms.
//For small lists where overhead and memory writing are costly.
//Heap Sort algorithm is based on it.