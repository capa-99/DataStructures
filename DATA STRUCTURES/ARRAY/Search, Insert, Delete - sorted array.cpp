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

int binarySearch(int_array* a, int element, int beg, int end)
{
    if(beg > end)
    {
        return -1;
    }
    int mid = (beg + end) / 2;
    if(a->arr[mid] == element)
    {
        return mid;
    }
    if(a->arr[mid] < element)
    {
        return binarySearch(a, element, mid + 1, end);
    }
    return binarySearch(a, element, beg, mid - 1);
}

int insert(int_array* a, int element)
{
    if(a->ptr >= a->n)
    {
        return -1;
    }
    int i = a->ptr;
    while((i >= 0) && (a->arr[i] > element))
    {
        a->arr[i+1] = a->arr[i];
        i--;
    }
    if(i >= 0)
    {
        a->arr[i+1] = element;
        a->ptr++;
        return a->ptr;
    }
    return -1;
}

int deleteEl(int_array* a, int element)
{
    int index = binarySearch(a, element, 0, a->ptr - 1);
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

int main()
{
    int_array numbers;
    numbers.n = 10;
    numbers.arr = new int[10];
    numbers.ptr = 0;

    insert(&numbers, 1);
    insert(&numbers, 5);
    insert(&numbers, 3);
    insert(&numbers, 2);
    insert(&numbers, 4);
    deleteEl(&numbers, 3);

    print(&numbers);
    
    cout << binarySearch(&numbers, 3, 0, numbers.ptr -1);

    return 0;
}