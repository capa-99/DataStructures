//Reversing an array means rearanging the elements such that the first element becomess the last, the second element becomes second last and so on

#include <iostream>
#include <vector>
#include <algorithm> 
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

//The idea is to use a temporary array to store the reverse of the array
//Create a temporary array of same size as the original array
//Copy all elements from original array to the temporary array in reverse order
//Copy all the elements from temporary array back to the original array
void reverseUsingATemporaryArray(int_array* a)
{
    int *temp = new int[a->ptr];
    for(int i = 0; i < a->ptr; i++)
    {
        temp[i] = a->arr[a->ptr-1-i];
    }
    for(int i = 0; i < a->ptr; i++)
    {
        a->arr[i] = temp[i];
    }
}
//time complexity: O(n), copying elements to a new array is a linear operation
//auxiliary space: O(n) because of an extra array to store the reversed array

//The idea is to maintain two pointers: left and right, such that left points at the beginning of the array and right points t the end of the array
//While left pointer is less than the right pointer, swap the lelemnts at these two pointers
//After each swap, increment the left pointer and decrement the roght pointer to move towards the center of array
//This will swap all the elements in the first half with their corresponding element in the second half
void reverseUsingTwoPointers(int_array* a)
{
    int beg = 0, end = a->ptr - 1, temp;
    while(beg < end)
    {
        temp = a->arr[beg];
        a->arr[beg] = a->arr[end];
        a->arr[end] = temp;
        beg++;
        end--;
    }
}
//time complexity: O(n), each element visited once
//auxiliary space: O(1)

//The idea is to iterate over the first half of the array and swap each element with its corresponding element form the end
//while iterating over the first half, any element at index i is swapped with the element at index (n-i-1)
void reverseBySwappingElemnts(int_array* a)
{
    int temp;
    for(int i = 0; i < a->ptr/2; i++)
    {
        temp = a->arr[i];
        a->arr[i] = a->arr[a->ptr-i-1];
        a->arr[a->ptr-i-1] = temp;
    }
}
//time complexity: O(n), the loop is linear, runs through half
//auxiliary space: O(1), no extra space required, in-place reversing

//The idea is to use recursion and define a recursive function that takes a range of array elements as input and reverses it
//Inside the recursive function: swap the first and the last element and recurively call the fucntion with the remaining subarray
void reverseUsingRecursion(int_array* a, int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int tmp = a->arr[left];
    a->arr[left] = a->arr[right];
    a->arr[right] = tmp;
    reverseUsingRecursion(a, left + 1, right - 1);
}
//O(n) time, O(n), space

//The idea is to use inbuilt reverse methods available accross different languages
void reverseUsingInbuiltMethods(vector<int>& a)
{
    reverse(a.begin(), a.end());
}
//time comlexity: O(n) - linear
//auxiliary space: O(1) - additional space is not used

int main()
{
    int_array numbers;
    numbers.n = 10;
    numbers.arr = new int[10];
    numbers.ptr = 5;
    numbers.arr[0] = 1;
    numbers.arr[1] = 4;
    numbers.arr[2] = 5;
    numbers.arr[3] = 6;
    numbers.arr[4] = 16;

    reverseUsingATemporaryArray(&numbers);
    reverseUsingTwoPointers(&numbers);
    reverseBySwappingElemnts(&numbers);
    reverseUsingRecursion(&numbers, 0, numbers.ptr - 1);

    vector<int> n = {1,4,5,6,16};
    reverseUsingInbuiltMethods(n);

    print(&numbers);

    return 0;
}