//Given two N x M matrices find a N x M matrix as the sum of given matrices
//Iterate over every cell of matrix (i, j), add the corresponding values of the two matrices and store in a single matrix - the resultant matrix.
//Initialize a resultant matrix res[N][M].
//Run a for loop for counter i as each row and in each iteration:
//Run a for loop for counter j as each column and in each iteration:
//Add values of the two matrices for index i, j and store in res[i][j].
//Return res.
void addition(int **A, int **B, int **C, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
//Time complexity: O(n x m). 
//Auxiliary space: O(n x m) since n2 extra space has been taken for storing results
//The program can be extended for rectangular matrices.