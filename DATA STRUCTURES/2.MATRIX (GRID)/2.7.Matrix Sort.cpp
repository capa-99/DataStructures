//Given a m x n matrix sort it in strict order. Strict order means that the matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= m-1, the first element is greater than or equal to the last element of row ‘i-1’.

//Naive Approach – O(mn Log mn) Time and O(mn) Space
//Store the matrix elements in a m x n sized 1D array, then sort the array and copy the elements back to the matrix,
void sort(int **A, int n, int m)
{
    int tmp* = new int[n*m];
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tmp[k] = A[i][j];
            k++;
        }
    }
    for(int i = 0; i < n*m; i++)
    {
        min = i;
        for(int j = i; j < n*m; j++)
        {
            if(tmp[j] < tmp[min])
            {
                min = j; 
            }
        }
        int t = tmp[i];
        tmp[i] = tmp[min];
        tmp[min] = t;
    }
    k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = tmp[k];
            k++;
        }
    }
}
//Time Complexity: O(mnlog2mn)
//Auxiliary Space: O(mn) for the auxiliary 1D array.

//Treating the Given Array as 1D Array – O(1) Space
//Treat the 2D-Array as a 1D-Array to sort the matrix without using extra space.
//For Accessing ith element of the matrix, the relation can be defined as: Ith Element of the Matrix = Mat[ i / n ][ i % n ]  where n is number of columns