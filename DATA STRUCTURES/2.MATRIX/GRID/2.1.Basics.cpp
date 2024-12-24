//Matrix or Grid is a two-dimensional array mostly used in mathematical and scientific calculations. It is also considered as an array of arrays, where array at each index has the same size.

//Representation of Matrix Data Structure:
//The elements are organized in rows and columns. The cell a[0][0] is the first element of the first row and first column.

//Declaration of Matrix Data Structure :
int arr[10][10];

//Initializing Matrix Data Structure:
//Assign some initial value to all the cells of the matrix.
int a[2][2] = { {1, 7}, {2, 6} };

//Operations on Matrix Data Structure:
//Access elements of Matrix
//Traversal of Matrix
/Searching in Matrix
//Sorting Matrix

//1. Access elements of Matrix Data Structure:
//Like one-dimensional arrays, matrices can be accessed randomly by using their indices to access the individual elements. A cell has two indices, one for its row number, and the other for its column number. We can use arr[i][j] to access the element which is at the ith row and jth column of the matrix.
a[0][0];

//2. Traversal of a Matrix Data Structure:
//We can traverse all the elements of a matrix or two-dimensional array by using two for-loops.
for(int i = 0; i < 10)
{
    for(int j = 0; j < 10; j++)
    {
        arr[i][j];
    }
}

//3. Searching in a Matrix Data Structure:
//We can search an element in a matrix by traversing all the elements of the matrix.
bool search(int **arr, int n, int m, int x)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == x)
            {
                return true;
            }
        }
    }
    return false;
}

//4. Sorting Matrix Data Structure:
//We can sort a matrix in two-ways:
//Sort the matrix row-wise
//Sort the matrix column-wise