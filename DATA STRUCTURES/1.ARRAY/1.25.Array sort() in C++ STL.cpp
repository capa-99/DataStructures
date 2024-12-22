//In C++, sort() is a built-in function used to sort the given range in desired order. It provides a simple and efficient way to sort the data in C++ but it only works on data structures that provide random access to its elements such as vectors and arrays.

//Syntax of sort()
//sort(first, last, comp);
//Parameters:
//first: Iterator to the beginning of the range to be sorted.
//last: Iterator to the element just after the end of the range.
//comp (optional): Binary function, functor, or lambda expression that compares two elements in the range. By default, is set as < operator 
//Return Value:
//This function does not return any value.

//Rules of Defining Comparator
//It should take two arguments of the same type as the elements being sorted.
//It should return true if the first argument should come before the second; otherwise, it should return false.

//Examples of sort()
//Sort Array in Ascending Order
#include <algorithm>
using namespace std;
void sortAscending(int *arr, int n)
{
    sort(arr, arr + n);
}

//Sort Array in Descending Order
bool comp(int a, int b)
{
    if(a > b)
    {
        return true;
    }
    return false;
}
void sortDescending(int *arr, int n)
{
    sort(arr, arr + n, comp);
}

//Sort Vector of User Defined Type
#include <vector>
class A {
    public: 
    int a;
    A(int x = 0): a(x) {}
};
bool comp(A x, A y)
{
    return x.a < y.a;
}
void sortUserType(vector<A> &arr)
{
    sort(arr.begin(), arr.end(), comp);
}
