//In C++, vector is a dynamic array with the ability to resize itself automatically when an element is inserted or deleted. It is a part of Standard Template Library (STL) and it provides various functions for data manipulation

//Syntax of Vector
//Vector is defined as the std::vector class template which contains its implementation and some useful member functions. It is defined inside the <vector> header file
//vector<T> vec_name
//where T is the type of elements in the vector, and vec_name is the name assigned to the vector

//Declaration and Initialization
//Declaration and initialization are processes of creting an instance of std::vector class and assigning it some initial value. Vector can be declared and initialized in multiple ways
//1. Default Initialization
//Creates an empty vector which can be filled later in the program
//vector<T> vec_name;
//2. Initialization with Size and Default Value
//vector<T> vec_name(size, value);
//3. Initialization Using Initializer List
//Initialized using a list of values enclosed in {} braces separated by comma
//vector<T> vec_name = {v1, v2, v3...};
//vector<T> vec_name({v1, v2, v3...});
#include <vector>
#include <iostream>
using namespace std;
vector<int> v1;
vector<int> v2 = {1, 4, 2, 3, 5};
vector<int> v3(5 ,9);

//Basic Vector Operations
//1. Accessing Elements
//Vector elements can be accessed using their index inside the [] subscript operator. This method is fast but doesn't check whether the given index exists in the vector or not. For safety accessing elements we can use vector at()
vector<char> v = {'a', 'c', 'f', 'd', 'z'};
cout << v[3] << endl;
cout << v.at(2);
//2. Updating Elements
//It uses the same methods: []subscript operator and vector at() with additional assignment operator to assign a new value to a particular element
vector<char> vv = {'a', 'c', 'f', 'd', 'z'};
v[3] = 'D';
v.at(2) = 'F';
//3. Traversing vector
//Vecto cna be traversed using indexes in a loop. The indexes start from 0 and go up to vector size - 1. The size of the vector can be determined using the vector size() method
vector<char> vvv = {'a', 'c', 'f', 'd', 'z'};
for(int i = 0; i < vvv.size(); i++)
{
    cout << vvv[i] << " ";
}
//4. Inserting Elements
//An element can be inserted using vector insert() which takes linear time. For the insertion at the end, we can use vector push_back() which is much faster, taking only constant time
vector<char> vvvv = {'a', 'f', 'd'};
vvvv.push_back('z');
vvvv.innsert(vvvv.begin() + 1, 'c');
//5. Deleting Elements
//An element can be deleted using vector erase(), but this methid needs iterator to the element to be deleted. If only the value of the element is known, then first use find() function to find its position
//For the deletion at the end vector pop_back() can be used and it's much faster, taking only constant time
vector<char> vvvvv = {'a', 'c', 'f', 'd', 'z'};
vvvvv.pop_back();
vvvvv.erase(find(vvvvv.begin(), vvvvv.end(), 'f'));

//Passing Vector to Functions
//It is recommended to pass the vector by reference to avoid the copying of all elements

//Multidimensional Vectors in C++
//We can create multidimensional vectors. Each element of a multidimensional vector can be visualized as the collection of vectors with dimension one less that the current vector

//All Member Functions of Vector
//Vector            Description
//push_back()       Adds an element to the end of the vector.
//pop_back()        Removes the last element of the vector.
//size()            Returns the number of elements in the vector.
//max_size()        Returns the maximum number of elements that the vector can hold.
//resize()          Changes the size of the vector.
//empty()           Checks if the vector is empty.
//operator[]        Accesses the element at a specific position.
//at()              Accesses the element at a specific position, with bounds checking.
//front()           Accesses the first element of the vector.
//back()            Accesses the last element of the vector.
//begin()           Returns an iterator pointing to the first element of the vector.
//end()             Returns an iterator pointing to the past-the-end element of the vector.
//rbegin()          Returns a reverse iterator pointing to the last element of the vector.
//rend()            Returns a reverse iterator pointing to the element preceding the first element of the vector.
//cbegin            Returns const_iterator to beginning 
//cend              Returns const_iterator to end
//crbegin           Returns const_reverse_iterator to reverse beginning
//crend             Returns const_reverse_iterator to reverse end
//insert()          Inserts elements at a specific position in the vector.
//erase()           Removes elements from a specific position or range in the vector.
//swap()            Swaps the contents of the vector with those of another vector.
//clear()           Removes all elements from the vector.
//emplace()         Constructs and inserts an element in the vector.
//emplace_back()    Constructs and inserts an element at the end of the vector.
//assign()          Assigns new values to the vector elements by replacing old ones.
//capacity()        Returns the size of the storage space currently allocated to the vector.
//reserve()         Requests that the vector capacity be at least enough to contain a specified number of elements.
//shrink_to_fit()   Reduces memory usage by freeing unused space.
//data()            Returns a direct pointer to the memory array used internally by the vector to store its owned elements. 
//get_allocator     Returns a copy of the allocator object associated with the vector.