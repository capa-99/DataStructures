//Array is a collection of items of the same variable type that are stored at contiguous memory locations

//Basic terminologies of Array
//Array Index: Elements are identified by their indexes. Array index stats from 0
//Array element: Elements are items store in an array and can be accessed by their index
//Array Lenght: The number of elements an array can contain

//Memory representation of Array
//All the elements are store in contiguous memory locations, so if we initialize an array, the elements will be allocated sequentially in memory

#include <vector>
#include <iostream>
using namespace std;

//Declaration of Array
int numbers[5];
char word[10];
float arr[20];

//Initialization of Array
int incrementing[] = {1, 2, 3, 4, 5};
char alphabet[5] = {'a', 'b', 'c', 'd', 'e'};
float values[10] = {1.4, 2.0, 24, 5.0, 0.0};

//Importance of Array
//Represents many instances in one variable

//Need or Applications of Array Data Structures
//Many other data structures ar implemented using arrays such as stacks and queues
//Representing data in tables and matrices
//Creating dynamic data structures such as Hash Tables and Graphs
//Have random access and cache friendliness

//Types of Arrays
//Types of arrays on the basis of Size
//1. Fixed Sized Arrays
//We cannot alter or update the size of this array. Only a fixed size (mentioned in []) of memory will be allocated for storage. It is not preferred when we don't know the size of the array
int fixed[5];
int fixed2[5] = {1, 2, 3, 4, 5};
int *fixedD = new int[5];
//2. Dynamic Sized Arrays
//The size of the array changes as per user requirements during execution of code. The memory is mostly dynamically allocated and de-allocated
vector<int> vect;
//Types of Arrays on the basis of Dimensions:
//1. One-dimensional Array(1-D array): a row where elements are sorted one after another
//Multi-dimensional Array: an array with more than one dimension: 2-D, 3-D, 4-D arrays etc.
//Two-dimensional Array(2-D array, matrix): an array of arrays, a matrix consisting of rows and columns
//Three-dimensional Array(3-D array): contains three dimensions, an array of two-dimensional arrays

struct int_array
{
   int *arr;
   int capacity;
   int n = 0;
};


//Operation on Array
//1. Array Traversal: (O(n) time, O(1) space)
//Array traversal involves visiting all the elements of the array once
void traverse(int_array *a)
{
    for(int i = 0; i < a->n; i++)
    {
        cout << a->arr[i] << " ";
    }
}
//2. Insertion in Array: (O(1) - O(n) time, O(1) - O(n) space)
//We can insert one or multiple elements at any position in the array
bool insert(int_array *a, int position, int element)
{
    if(a->n == a->capacity)
    {
        return false;
    }
    if(position > a->n)
    {
        return false;
    }
    for(int i = a->n - 1; i >= position; i--)
    {
        a->arr[i+1] = a->arr[i];
    }
    a->arr[position] = element;
    a->n++;
    return true;
}
//3. Deletion in Array: (O(1) - O(n) time, O(1) - O(n) space)
//We can delete an element at any index in an array
int find(int_array* a, int element);
bool deleteEl(int_array *a, int element)
{
    int position = find(a, element);
    if(position == -1)
    {
        return false;
    }
    for(int i = position; i < a->n - 1; i++)
    {
        a->arr[i] == a->arr[i+1];
    }
    a->n--;
    return true;
}
//4. Searching in Array (O(1) - O(n) time, O(1) space)
//We can traverse over an array and search for an element
int find(int_array *a, int element)
{
    for(int i = 0; i < a->n; i++)
    {
        if(a->arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

//Advantages of Array
//Random access to elements which makes accessing elements by position faster
//Better cache locality which makes a pretty big difference in performance
//Representing multiple data itemsof the same type using a single name
//Implementing of other data structures like linked lists, stacks, queues, trees, graphs...

//Disadvantages of Array
//Once the memory is allocated, it cannot be increased or decreased, making it impossible to store extra data if required
//Allocating less memory than required  to an array leads to loss of data
//A single array cannot store values of different data types
//Contiguous memory locations make deletion and insertion very difficult to implement

//Applications of Array
//Implementation of other data structures (array lists, heaps, hash tables, vectors, matrices)
//Implementation of database records
//Lookup tables by computer

//Conclusion
//Arrays are a simple method of accessing elements of the same type by grouping them and we can find the elements efficiently by their indexes and can perform different operations using them. Theyare more efficient at memory allocation