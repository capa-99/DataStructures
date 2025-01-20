//Given a matrix of size n X m, find the transpose of it. Transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words,  changing mat[i][j] to mat[j][i].
//Follow the given steps:
//Run a nested loop using two integer pointers i and j for 0 <= i < n and 0 <= j < m
//Set mat[i][j] equal to mat[j][i]
void transposeMatrix(int** A, int** B, int n, int m)
{
    B = new int*[m];
	for(int i = 0; i < m; i++)
	{
    	B[i] = new int[n];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			B[j][i] = A[i][j];
		}
	}
}
//Time complexity: O(m x n).
//Auxiliary Space: O(m x n)

//Approach using constant space for Square Matrix
//This approach works only for square matrices. This algorithm is also known as an “in-place” algorithm as it uses no extra space to solve the problem.
//Follow the given steps:
//Run a nested loop using two integer pointers i and j for 0 <= i < N and i+1 <= j < N
//Swap mat[i][j] with mat[j][i]
void transposeSquareMatrix(int** A, int n)
{
    for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
            int tmp = A[j][i];
			A[j][i] = A[i][j];
            A[i][j] = tmp;
		}
	}
}
//Time complexity: O(n²)
//Auxiliary Space: O(1)