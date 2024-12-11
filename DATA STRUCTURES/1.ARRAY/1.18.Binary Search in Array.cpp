//Binary Search Algorithm is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N).

//What is Binary Search Algorithm?
//Binary search is a search algorithm used to find the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half until the target value is found or the interval is empty. The search interval is halved by comparing the target element with the middle value of the search space.

//Conditions to apply Binary Search Algorithm in a Data Structure
//The data structure must be sorted.
//Access to any element of the data structure should take constant time.

//Binary Searh Algorithm
//Divide the search space into two halves by finding the middle index “mid”. 
//Compare the middle element of the search space with the key. 
//If the key is found at middle element, the process is terminated.
//If the key is not found at middle element, choose which half will be used as the next search space.
//If the key is smaller than the middle element, then the left side is used for next search.
//If the key is larger than the middle element, then the right side is used for next search.
//This process is continued until the key is found or the total search space is exhausted.

//How to Implement Binary Search Algorithm?
//The Binary Search Algorithm can be implemented as
//Iterative Binary Search Algorithm
//Recursive Binary Search Algorithm

//Iterative Binary Search Algorithm
//A while loop is used to continue the process of comparing the key and splitting the search space in two halves
int binarySearchIterativeAlgorithm(int *arr, int n, int key)
{
    int beg = 0, end = n - 1, mid;
    while(beg <= end)
    {
        mid = (beg + end) / 2;
        if(arr[mid] == key)
        {
            return mid;
        }
        if(key > arr[mid])
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
//Time Complexity: O(logN)
//Auxiliary Space: O(1)

//Recursive Binary Search Algorithm
//Create a recursive function and compare the mid of the search space with the key. And based on the result either return the index where the key is found or call the recursive function for the next search space.
int binarySearch(int *arr, int beg, int end, int key)
{
    if(beg > end)
    {
        return -1;
    }
    int mid = (beg + end) / 2;
    if(arr[mid] == key)
    {
        return mid;
    }
    if(key > arr[mid])
    {
        binarySearch(arr, mid + 1, end, key);
    }
    else
    {
        binarySearch(arr, beg, mid - 1, key);
    }
}
int binarySearchRecursiveAlgorithm(int *arr, int n, int key)
{
    return binarySearch(arr, 0, n - 1, key);
}

//Complexity Analysis of Binary Search Algorithm
//Time Complexity: 
//Best Case: O(1)
//Average Case: O(log N)
//Worst Case: O(log N)
//Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(logN).

//Applications of Binary Search Algorithm
//as a building block for more complex algorithms used in machine learning, for training neural networks or finding the optimal hyperparameters for a model.
//for searching in computer graphics for ray tracing or texture mapping.
//for searching a database.

//Advantages of Binary Search
//Faster than linear search
//More efficient than other searching algorithms with a similar time complexity
//Well-suited for searching large datasets that are stored in external memory

//Disadvantages of Binary Search
//The array should be sorted.
//The data structure has to be stored in contiguous memory locations. 
//The elements of the array have to be comparable