//Given a matrix mat[n][m] and an element target. return true if the target is present in the matrix, else return false.
//Traverse the mat[][] and compare target with every element of the matrix. If matches, then return true. If we reach the end return false.
bool searchMat(int **mat, int n, int m, int target)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
//Time Complexity : O(n * m), where n and m are the numbers of rows and columns of matrix.
//Auxiliary Space : O(1)