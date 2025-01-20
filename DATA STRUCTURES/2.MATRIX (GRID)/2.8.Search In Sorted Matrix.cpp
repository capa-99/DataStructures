//Given a sorted matrix mat[][] of size nxm and an element x,  find if x is present in the matrix or not. Matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row i, where 1 <= i <= n-1, the first element of row i is greater than or equal to the last element of row i-1.

//Comparing with all elements – O(n*m) Time and O(1) Space
//Iterate through the entire matrix mat[][] and compare each element with x. If an element matches the x, return true. Otherwise, at the end of the traversal, return false.

//Using Binary Search Twice – O(logn + logm) Time and O(1) Space
//Locate the row where the target x might be by using binary search, and then apply binary search again within that row.
//To find the correct row, perform binary search on the first elements of the middle row.
//Start with low = 0 and high = n – 1.
//If x is smaller than the first element of the middle row (a[mid][0]), then x will be smaller than all elements in rows >= mid, so update high = mid – 1.
//If x is greater than the first element of the middle row (a[mid][0]), then x will be greater than all elements in rows < mid, so store the current mid row and update low = mid + 1.
//Once the correct row is found, apply binary search within that row to search for the target element x.
bool searchUsingBinarySearchTwice(int **A, int n, int m, int x)
{
    int high = n - 1, low = 0, mid;
    int i;
    while(low <= high)
    {
        mid = (high + low) / 2;
        if(A[mid][0] == x)
        {
            i = mid;
            break;
        }
        else
        {
            if(A[mid][0] < x)
            {
                low = mid + 1;
                i = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    high = m - 1, low = 0;
    while(low <= high)
    {
        mid = (high + low) / 2;
        if(A[i][mid] == x)
        {
            return true;
        }
        else
        {
            if(A[mid][0] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

//Using Binary Search Once – O(log(n*m)) and O(1) Space
//Consider the given matrix as 1D array and apply only one binary search. For a matrix of size n x m and consider it as a 1D array of size n*m, then the first index would be 0 and the last index n*m-1. Do binary search from low = 0 to high = (n*m-1).
//How to find the element in 2D matrix corresponding to index = mid?
//Since each row of mat[][] will has m elements, find the row of the element as (mid / m) and the column of the element as (mid % m). Then, compare x with arr[mid/m][mid%m] for each mid and complete binary search.
bool searchUsingBinarySearchOnce(int **A, int n, int m, int x)
{
    int high = n * m - 1, low = 0, mid;
    while(low <= high)
    {
        mid = (high + low) / 2;
        if(A[mid/m][mid%m] == x)
        {
            return true;
        }
        else
        {
            if(A[mid/m][mid%m] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}