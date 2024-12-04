//Given an array, arr[] of size N, print the elements of the given array present at odd indices (1-based indexing).

//The simplest approach to solve this problem is to traverse the given array and check if the position of the current element is odd or not. If true, then print the current element.
void printAlternates(int* arr, int n)
{
    for(int i = 0; i <  n; i++)
    {
        if(i % 2 == 1)
        {
            cout << arr[i] << " ";
        }
    }
}
//Time Complexity: O(N)
//Auxiliary Space: O(1)

//Recursive Approach: To print the alternate elements, increase the index with +2
void printAlternatesRecursiveApproach(int* arr, int n, int i)
{
    if(i == n)
    {
        return;
    }
    if(i == (n - 1))
    {
        cout << arr[i];
        return;
    }
    cout << arr[i] << " ";
    printAlternatesRecursiveApproach(arr, n, i + 2);
}
//Time Complexity: O(N)
//Auxiliary Space: O(N)

//To optimize the above approach, traverse only those elements which are present at odd positions.
//Iterate a loop with a loop variable currIndex from 0 to N.
//Print the value of arr[currIndex] and increment the value of currIndex by 2 until currIndex exceeds N.
void printAlternate(int* arr, int n)
{
    for(int i = 1; i < n; i = i + 2)
    {
        cout << arr[i] << " ";
    }
}
//Time Complexity: O(N)
//Auxiliary Space: O(1)