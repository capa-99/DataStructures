//Rotations in the array are rearranging the elements by shifting each element to a new position. The rotation can be clockwise or counterclockwise.

//Types of Rotation in Array
//1. Right Rotation (or Clockwise)
//The array elements are shifted towards the right
//2. Left Rotation (or Counter Clockwise)
//The array elements are shifted towards the left

//How to implement rotations in an array?

//1. Rotate one by one
//At each iteration, shift the elements by one position to the right in a circular fashion (the last element becomes the first). Perform this operation d times to rotate the elements to the right by d positions.
void rotateOneByOne(int *arr, int n, int d)
{
    for(int i = 0; i < d; i++)
    {
        int tmp = arr[n-1];
        for(int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = tmp;
    }
}
//Time Complexity: O(n*d)
//Auxiliary Space: O(1)

//2. Using Temporary Array
//Use a temporary array of size n, where n is the length of the original array. If we right rotate the array by d positions, the last d elements will be in the beginning and the first (n – d) at the end. 
//Copy the last d elements of the original array into the first d positions of the temporary array
//Copy the first n – d elements of the original array to the end of temporary array. 
//Copy all the elements of temporary array back into the original array.
void rotateUsingTemporaryArray(int *arr, int n, int d)
{
    int *tmp = new int[n];
    d = d % n;
    for(int i = 0; i < d; i++)
    {
        tmp[i] = arr[n-d+i];
    }
    for(int i = 0; i < n - d; i++)
    {
        tmp[d+i] = arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = tmp[i];
    }
}
//Time complexity: O(n), where n is the size of array
//Auxiliary Space: O(n)

//3. Juggling Algorithm
//Instead of moving one by one, we can use the concept of cycles. Each cycle is independent and represents a group of elements that will shift among themselves during the rotation. If the starting index of a cycle is i, then the next elements will be present at indices (i + d) % n, (i + 2d) % n, (i + 3d) % n … till we reach back to index i. 
//For any index i, we know that element at index i will move to index (i + d) % n. We can simply rotate all elements in the same cycle without interfering with any other cycle. 
#include <algorithm>
using namespace std;
void rotateJugglingAlgorithm(int *arr, int n, int d)
{
    d = d % n;
    int cycles = __gcd(d, n);
    for(int i = 0; i < cycles; i++)
    {
        int current = i;
        int next;
        int hold = arr[current];
        do
        {
            next = (current + d) % n;
            int tmp = hold;
            hold = arr[next];
            arr[next] = tmp;
            current = next;
        }while(current != i);
        
    }
}

//4. The Reversal Algorithm
//If we right rotate the array by d positions, the last d elements will be in the front and first (n – d) at the end. 
//Reverse all the elements of the array. 
//Reverse first d elements.
//Reverse last (n – d) elements to get the final rotated array.
void rotateTheReversalAlgorithm(int *arr, int n, int d)
{
    for(int i = 0; i < n / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = tmp;
    }
    for(int i = 0; i < d / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[d-1-i];
        arr[d-i-1] = tmp;
    }
    for(int i = d; i < (n+d) / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n-i+d-1];
        arr[n-1-i+d] = tmp;
    }
}
//Time Complexity: O(n)
//Auxiliary Space: O(1)