//Ginven an array arr[] of size n, the task is to find all the leaders in the array - elements that are greater than all the elements to their right side
//Note: the rightmost element is always a leader

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

//O(n²) time and O(1) space
//Use two loops: the outer loop runs from 0 to size - 1 and one by one picks all elements from left to right and the inner loop compares the picked element to all the elements on its right side
//If the picked element is greater than all the elements to its right side, then the picked element is a leader
void findLeadersUsingNestedLoops(int_array* a, int_array* result)
{
    for(int i = 0; i < a->n; i++)
    {
        int j = i + 1;
        while(j < a->n && a->arr[j] < a->arr[i] )
        {
            j++;
        }
        if(j == a->n)
        {
            result->arr[result->n] = a->arr[i];
            result->n++;
        }
    }
}

//O(n) time and O(1) space
//The idea is to scan all the elements from right to left in an array and keep track of the maximum till now
//When the maximum changes its value, add it to the result
//Finally, reverse the result
void findLeadersUsingSuffixMaximum(int_array* a, int_array* result)
{
    int maximum = 0;
    for(int i = a->n - 1; i >= 0; i--)
    {
        if(a->arr[i] > maximum)
        {
            maximum = a->arr[i];
            result->arr[result->n] = maximum;
            result->n++;
        }
    }

    for(int i = 0; i < result->n / 2; i++)
    {
        int temp = result->arr[i];
        result->arr[i] = result->arr[result->n-i-1];
        result->arr[result->n-i-1] = temp;
    }
}

int main()
{
    int_array numbers, result;
    numbers.n = 5;
    numbers.arr = new int[15];
    numbers.arr[0] = 17;
    numbers.arr[1] = 5;
    numbers.arr[2] = 8;
    numbers.arr[3] = 17;
    numbers.arr[4] = 11;
    
    result.n = 0;
    result.arr = new int[15];
    findLeadersUsingNestedLoops(&numbers, &result);
    findLeadersUsingSuffixMaximum(&numbers, &result);

    print(&numbers);
    print(&result);

    return 0;
}