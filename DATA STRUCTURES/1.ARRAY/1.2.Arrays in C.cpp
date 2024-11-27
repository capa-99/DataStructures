//Array in C is one of the most used data structures in  C programming

//What is Array in C?
//An array in C is a fixed-size collection of similar data items stored in contiguous memory locations. It can be used to store primitive data types: int, char, float..., and derived and user-friendly types: pointers, structures...

//C array declaration
//An array has to be declared before using it. It is declared by specifying its name, the type of its elements and the size of its dimensions. The compiler allocates the memory block of the specifid size to the array name
//data_type array_name[size];
//or
//data_type array_name[size1][size2]...[sizeN];
//where N is the number of dimensions
//The C arrays are static in nature - they are allocated at the compile time
int arr_int[5];
char arr_char[5];

//C Array Initialization
//Initialization in C is the process to assign some initial value to the variable. When the array is declared, the elements contain garbage values
//1. Array Initialization with Declaration
//The array is initialized along with its declaration. We use an initializer list to initialize multiple elements. An initializer list is the list of values enclosed with braces {} separated by a comma.
//data_type array_name[size] = {value1, value2, ... valueN};
//2. Array Initialization with Declaration without Size
//If we initialize an array using initializer list, we can skip declaring the size of the array as the compiler can automatically deduce the size which is going to be equal to the number of elements present in the initializer list
//data_type array_name[] = {1, 2, 3, 4, 5};
//3. Array Initialization after Declaration (using loops)
//We initialize the array after the decllaration by asigning the initial value of each element individually. We can use for, while, do-while loops.
//for(int i = 0; i < N; i++){
//  array_name[i] = valuei;
//}
int arr[5] = {10, 20, 30, 40, 50};
int arr1[] = {1, 2, 3, 4, 5};
float arr2[5];
for(int i = 0; i < 5; i++)
{
    arr2[i] = 16*i + 57;
}

//Access Array Elements
//We can access any element of an array in C using the array subscript operator [ ]  and the index value i of the element.
//The indexing in the array always starts with 0, the first element is at index 0 and the last element is at N – 1 where N is the number of elements in the array.
int arr4[5] = { 15, 25, 35, 45, 55 };
printf("Element at arr[2]: %d\n", arr4[2]);

//Update Array Element
//We can update the value of an element at the given index i by using the array subscript operator [ ] and assignment operator =.
//array_name[i] = new_value;

//C Array Traversal
//Traversal is the process in which we visit every element of the data structure. For C array traversal, we use loops to iterate through each element of the array.
//for (int i = 0; i < N; i++) {
//    array_name[i];
//}

//Types of Array in C
//There are two types of arrays based on the number of dimensions they have:
//One Dimensional (1D)
//Multidimensional

//1. One Dimensional Array in C
//The arrays that have only one dimension.
//array_name [size]; 
//Array of Characters (Strings)
//In C, we store the words, a sequence of characters in the form of an array of characters terminated by a NULL character. These are called strings in C

//2. Multidimensional Array in C
//Arrays that have more than one dimension
//A. Two-Dimensional Array in C
//An array that has exactly two dimensions. They can be visualized in the form of rows and columns organized in a two-dimensional plane.
//array_name[size1] [size2];
//size1: Size of the first dimension.
//size2: Size of the second dimension.
//B. Three-Dimensional Array in C
//A 3D array has exactly three dimensions. It can be visualized as a collection of 2D arrays stacked on top of each other
//array_name [size1] [size2] [size3];

//Relationship between Arrays and Pointers
//The array name is a constant pointer to the first element of the array and the array decays to the pointers when passed to the function.

//Passing an Array to a Function in C
//An array is always passed as pointers to a function in C.

//Return an Array from a Function in C
//In C, we can only return a single value from a function. To return multiple values or elements, we have to use pointers.

//Properties of Arrays in C
//1. Fixed Size - The size of the array must be known at the compile time and it cannot be changed once it is declared.
//2. Homogeneous Collection We can only store one type of element in an array. 
//3. Indexing in Array - The array index always starts with 0 
//4. Dimensions of an Array - the number of indexes required to refer to an element in the array. 
//5. Contiguous Storage - All the elements in the array are stored continuously one after another in the memory.
//6. Random Access -  we can get to a random element at any index in constant time complexity just by using its index number.
//7. No Index Out of Bounds Checking - it is not a compiler error to initialize an array with more elements than the specified size.

//Advantages of Array in C
//1. Random and fast access of elements using the array index.
//2. Use of fewer lines of code as it creates a single array of multiple elements.
//3. Traversal through the array becomes easy using a single loop.
//4. Sorting becomes easy as it can be accomplished by writing fewer lines of code.

//Disadvantages of Array in C
//1. Allows a fixed number of elements to be entered which is decided at the time of declaration. 
//2. Insertion and deletion of elements can be costly since the elements are needed to be rearranged after insertion and deletion.