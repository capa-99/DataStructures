//Given an array of integers arr[] of size n, rotate the array elements to the left by d positions

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

//In each iteration, shift the elements by one position to the left in a circular fashion (the first element becomes the last)
//Perform this operation d times to rotate the elements to the left by d positions
void rotateOneByOne(int_array* a, int d)
{
   for(int i = 0; i < d; i++)
   {
    int tmp = a->arr[0];
        for(int j = 0; j < a->n - 1; j++)
        {
            a->arr[j] = a->arr[j+1];
        }
        a->arr[a->n - 1] = tmp;
   }
}
//Time Complexity: O(d*n), the outer loop runs d times, and within each iteration, the inner loop shifts all n elements
//Auxiliary Space: O(1)

//The idea is to use a temporary array of size n, where n is the length of the original array
//If we rotate the array by d positions, the last n - d elements will be at the front and the first d elements will be at the end
//Copy the last (n - d) elements of original array into the first n - d positions of temporary array
//Then copy the first d elements of the original array to the end of temporary array
//Finally, copy all the elements of temporary array back into the original array
void rotateUsingTemporaryArray(int_array* a, int d)
{
    int_array temp;
    temp.n = a->n;
    temp.arr = new int[temp.n];
    d = d % a->n;
    for(int i = 0; i < a->n - d; i++)
    {
        temp.arr[i] = a->arr[i+d];
    }
    for(int i = 0; i < d; i++)
    {
        temp.arr[a->n-d+i] = a->arr[i];
    }
    for(int i = 0; i < a->n; i++)
    {
        a->arr[i] = temp.arr[i];
    }
}
//Time Complexity: O(n), as weare visiting each element twice
//Auxiliary Space: O(n), as we are using a temporary array

//Rotate Using Juggling Algorithm
//The idea is to use Juggling Algorithm which is based on rotating elements in cycles
//Each cycle is independent and represents a group of elements that will shift among themselves during the rotation
//If the starting index of a cycle i i then next elements of the cycle can be found at indices (i+d)%n, (i+2d)%n, (i+3d)%n... and so on till we return to the original index i
//For any array index i, after rotation, the element that will occupy this position is arr[(i+d)%n]
//Consequently, for every index in the cycle, place the element that should be in that position after the rotation is completed
//Time Complexity: O(n)
//Auxiliary Space: O(1)

//The idea is based on the observation that if we left rotate the array by d positions, the last (n-d) elements will be at the front and the first d elements will be at the end
//Reverse the subarray containing the first d elements of the array
//Reverse the subarray containing the last (n-d) elements of the array
//Finally, reverse all the elements of the array
void rotateUsingReversalAlgorithm(int_array* a, int d)
{
    d = d % a->n;
    for(int i = 0; i < d / 2; i++)
    {
        int temp = a->arr[i];
        a->arr[i] = a->arr[d-i-1];
        a->arr[d-i-1] = temp;
    }
    for(int i = d; i < d + (a->n - d) / 2; i++)
    {
        int temp = a->arr[i];
        a->arr[i] = a->arr[a->n+d-i-1];
        a->arr[a->n+d-i-1] = temp;
    }
    for(int i = 0; i < a->n / 2; i++)
    {
        int temp = a->arr[i];
        a->arr[i] = a->arr[a->n-i-1];
        a->arr[a->n-i-1] = temp;
    }
}
//Time Complxity: O(n), as we are visting each element twice
//Auxiliary space: O(1)


int main()
{
    int_array big;
    big.n = 6;
    big.arr = new int[6];
    for(int i = 0; i < 6; i++)
    {
        big.arr[i] = i + 9;
    }
     
    rotateOneByOne(&big, 2);
    rotateUsingTemporaryArray(&big, 2);
    rotateUsingReversalAlgorithm(&big, 2);

    print(&big);

    return 0;
}