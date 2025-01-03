//Given two m x n matrices m1 and m2, subtract m2 from m1 and return res.
//Traverse both matrices element by element and subtract m2[i][j] from m1[i][j].
void substraction(int **A, int **B, int **C, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
//Time complexity: O(n²)