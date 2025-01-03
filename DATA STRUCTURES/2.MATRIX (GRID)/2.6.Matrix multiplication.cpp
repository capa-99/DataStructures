//Given two matrices, multiply them. Matrices can either be square or rectangular:

//Multiplication of two Square or Rectangular Matrices
//The number of columns in Matrix-1 must be equal to the number of rows in Matrix-2.
//Output of multiplication of Matrix-1 and Matrix-2, results with equal to the number of rows of Matrix-1 and  the number of columns of Matrix-2 i.e. rslt[R1][C2]
bool multiplication(int **A, int **B, int **C, int rA, int rB, int cA, int cB)
{
    if(cA != rB)
    {
        return false;
    }
    for(int i = 0; i < rA; i++)
    {
        for(int j = 0; j < cB; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < cA; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return true;
}
//Time complexity: O(R1 * C2 * R2) for given matrices mat1[R1][C1] and mat2[R2][C2]
//Auxiliary space: O(R1 * C2)

//Multiplication of Rectangular Matrices using Pointers in C/C++:
//Use pointers in C/C++ to multiply matrices
#define CA 5
#define CB 5
bool multiplication(int (*A)[CA], int (*B)[CB], int (*C)[CB], int rA, int rB)
{
    if(CA != rB)
    {
        return false;
    }
    for(int i = 0; i < rA; i++)
    {
        for(int j = 0; j < CB; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < CA; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return true;
}


