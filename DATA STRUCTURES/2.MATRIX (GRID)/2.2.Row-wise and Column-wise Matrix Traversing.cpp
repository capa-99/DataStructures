//Two common ways of traversing a matrix are row-major-order and column-major-order
//Row Major Order: When matrix is accessed row by row. 
//Column Major Order: When matrix is accessed column by column.
//According to time complexity, both lead to O(n²), but when it comes to cache level one of the orders access will be faster compared to another. In C++, matrix is stored in row major form so while accessing the i+1th element after ith, it will most probably lead to a hit, which will further reduce the time of the program. 
void rowTraverse(int **arr, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j];
        }
    }
}
void columnTraverse(int **arr, int n, int m)
{
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            arr[i][j];
        }
    }
}
//Time Complexity: O(MAX*MAX)
//Auxiliary Space: O(MAX*MAX)