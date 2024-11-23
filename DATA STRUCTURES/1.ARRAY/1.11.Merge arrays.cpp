//There are two sorted  arrys: first one is of size m+n containing only m elements and another one is of size n and contains n elements
//Merge these two arrays into the first array of size m+n such that the output is sorted
//Algorithm: let first array be mPlusN[] and other array be N[]
//1) Move m elements of mPlusN[]to end
//2) Start from nth element of mPlusN[] and 0th element of N[]and merge them into mPlusN[]

#include <iostream> 
using namespace std;

struct int_array
{
    int* arr;
    int n;
};

void print(int_array* a)
{
    for(int i = 0; i < a->n; i++)
    {
        cout << a->arr[i] << " ";
    }
}
void merge(int_array* a, int_array* b)
{
    int i = a->n - b->n - 1, j = b->n - 1, k = a->n - 1;
    while(k >= 0 && i >= 0 && j >= 0)
    {
        if(a->arr[i] > b->arr[j])
        {
            a->arr[k] = a->arr[i];
            i--;
        }
        else
        {
            a->arr[k] = b->arr[j];
            j--;
        }
        k--;
    }
    if(i = -1 && j >= 0)
    {
        for(int l = 0; l < k; l++)
        {
            a->arr[l] = b->arr[l];
        }
    }
}
//Time comlexity: O(m+n)
//Auxiliary space: O(1)

int main()
{
    int_array big, small;
    big.n = 10;
    big.arr = new int[10];
    small.n = 6;
    small.arr = new int[6];
    for(int i = 0; i < 4; i++)
    {
        big.arr[i] = i + 8;
        small.arr[i] = i;
    }
    small.arr[4] = 7;
    small.arr[5] = 12;
    
    merge(&big, &small);

    print(&big);

    return 0;
}