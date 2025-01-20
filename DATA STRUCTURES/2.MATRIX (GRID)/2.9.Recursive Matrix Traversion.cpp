//Given a matrix mat[][] of size n x m, traverse it using recursion.
//Approach: 
//Check if the current position is in the bottom-right corner of the matrix
//Print the value at that position
//End the recursion
//Print the value at the current position
//Check if the end of the current row has not been reached
//Move right
//Check if the end of the current column has been reached
//Move down to the next row
#include <iostream>
using namespace std;
void recursive(int** A,  int n, int m, int posi, int posj)
{
    if(posj == m-1 && posi == n-1)
    {
        cout << A[posi][posj];
        return;
    }
    if(posj < m)
    {
        cout << A[posi][posj] << " ";
        recursive(A, n, m, posi, posj + 1);
    }
    else
    {
        if(posi < n)
        {
            cout << endl;
            recursive(A, n, m, posi + 1, 0);
        }
    } 
}
void recursiveTraversal(int** A, int n, int m)
{
    recursive(A, n, m, 0, 0);
}
//Time Complexity: O(N * M)
//Auxiliary Space: O(M), because of recursive calling