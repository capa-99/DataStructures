#include <iostream>
using namespace std;

struct int_array
{
    int* arr;
    int n;
    int ptr;
};

void print(int_array* a)
{
    for(int i = 0; i < a->ptr; i++)
    {
        cout << a->arr[i] << " ";
    }
}

//In an unsorted array, the search operation can be berformed by linear traversal from the firt element to the last element
int search(int_array* a, int element)
{
    for(int i = 0; i < a->ptr; i++)
    {
        if(a->arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
//time complexity O(N)
//auxiliary space O(1)

//we don't have to care about the positon at whih the element is to be placed, so t's fater than in a sorted array
int insertAtEnd(int_array* a, int element)
{
    if(a->ptr == a->n)
    {
        return -1;
    }
    a->arr[a->ptr] = element;
    a->ptr++;
    return a->ptr;
}
//time complexity O(1)
//auxiliary space O(1)

//performed by shifting elements that are on the right side of the required position to the right
int insertAtPos(int_array* a, int element, int position)
{
    if(a->ptr == a->n)
    {
        return -1;
    }
   for(int i = a->ptr; i > position; i--)
   {
        a->arr[i] = a->arr[i-1];
   }
   a->arr[position] = element;
   a->ptr++;
   return a->ptr;
}
//time complexity O(N)
//auxiliary space O(1)

//the element to be deleted is searched using the linear search, and then the delete operation is performed followed by shifting the elements
int deleteEl(int_array* a, int element)
{
    int index = search(a, element);
    if(index == -1)
    {
        return -1;
    }
    for(int i = index; i < a->ptr-1; i++)
    {
        a->arr[i] = a->arr[i+1];
    }
    a->ptr--;
    return a->ptr;
}
//time complexity O(N)
//auxiliary space O(1)


int main()
{
    int_array numbers;
    numbers.n = 10;
    numbers.arr = new int[10];
    numbers.ptr = 0;

    insertAtEnd(&numbers, 1);
    insertAtEnd(&numbers, 5);
    insertAtEnd(&numbers, 3);
    insertAtEnd(&numbers, 2);
    insertAtEnd(&numbers, 1);
    insertAtEnd(&numbers, 4);
    insertAtEnd(&numbers, 1);
    insertAtPos(&numbers, 11, 2);
    deleteEl(&numbers, 11);

    print(&numbers);


    return 0;
}