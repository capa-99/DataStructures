//The determinant of a Matrix is defined as a special number only for square matrices. It represents the matrix in terms of a real number
//How to calculate? 
//The value of the determinant of a matrix can be calculated by the following procedure: 
//For each element of the first row or first column get the cofactor of those elements.
//Multiply the element with the determinant of the corresponding cofactor. 
//Add them with alternate signs. As a base case, the value of the determinant of a 1*1 matrix is the single value itself. 
//The cofactor of an element is a matrix that we can get by removing the row and column of that element from that matrix.
int determinant(int** A, int n)
{
    if(n == 1)
    {
        return A[0][0]
    }
    if(n == 2)
    {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
    int res = 0;
    int sign = 1;
    int** tmp = new int*[n-1];
    for(int i = 0; i < n - 1; i++)
    {
        tmp[i] = new int[n-1];
    }
    for (int col = 0; col < n; col++) 
    {
        for (int i = 1; i < n; i++) 
        {
            int subcol = 0;
            for (int j = 0; j < n; j++) 
            {
                if (j == col) 
                {
                    continue; 
                }
                tmp[i - 1][subcol] = A[i][j]; 
                subcol++;
            }
        }
        sign = sign * -1; 
        res = res + sign * A[0][col] * determinant(tmp, n - 1);
    }
    return res; 
}
//Time Complexity: O(n⁴)
//Space Complexity: O(n²), Auxiliary space used for storing cofactors.
//Note: In the above recursive approach when the size of the matrix is large it consumes more stack size.

//Determinant of a Matrix using Determinant properties:
//Calculate the determinant of an N x N matrix using Gaussian elimination and a series of transformations that reduce the matrix to upper triangular form.
//Convert the given matrix into an upper triangular matrix using determinant properties 
//The determinant of the upper triangular matrix is the product of all diagonal elements. 
//Iterate every diagonal element and make all the elements down the diagonal zero using determinant properties 
//If the diagonal element is zero then search for the next non-zero element in the same column.
//There are two cases:
//Case 1: If there are no non-zero elements, the determinant of a matrix is zero 
//Case 2: If there is a non-zero element there are two cases 
//Case A: If the index is with a respective diagonal row element, using the determinant properties make all the column elements down to zero
//Case B: Swap the row with respect to the diagonal element column and continue the Case A operation.
#include <iostream>
#include <cmath>
using namespace std;
int determinantWithProperties(int** A, int n) 
{
    int num1, num2, det = 1, index, total = 1; 
    int* temp = new int[n+1];
    for (int i = 0; i < n; i++) 
    {
        index = i; 
        while (index < n && A[index][i] == 0) 
        {
            index++;
        }
        if (index == n)
        {
            continue;
        }
        if (index != i) 
        {
            for (int j = 0; j < n; j++) 
            {
                int t = A[i][j];
                A[i][j] = A[index][j];
                A[index][j] = t;
            }
            det = det * pow(-1, index - i);
        }
        for (int j = 0; j < n; j++) 
        {
            temp[j] = A[i][j];
        }
        for (int j = i + 1; j < n; j++) 
        {
            num1 = temp[i]; 
            num2 = A[j][i];
            for (int k = 0; k < n; k++) 
            {
                A[j][k] = (num1 * A[j][k]) - (num2 * temp[k]);
            }
            total = total * num1; 
        }
    }
    for (int i = 0; i < n; i++) 
    {
        det = det * A[i][i];
    }
    return (det / total);
}
//Time complexity: O(n3) 
//Auxiliary Space: O(n), Space used for storing a row.