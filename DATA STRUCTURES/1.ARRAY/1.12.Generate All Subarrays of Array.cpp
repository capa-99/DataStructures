//Given an array, generate all the possible subarrays of the given array using recursion.

//Iterative Approach
//Use three nested loops
//Outermost Loop : Picks starting index of current subarray
//Middle Loop : Picks ending point of current subarray
//Innermost Loop : Prints the subarray from the starting point to the ending point
void generateSubarrays(int *arr, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i; j < n; j++)
        {
            cout << "[";
            for(int k = i; k <= j; k++)
            {
                cout << arr[k] << ", ";
            }
            cout << "]";
        }
    }
}

//Recursive Approach
//Use two pointers start and end to maintain the starting and ending point of the array and follow the steps given below: 
//Stop if we have reached the end of the array
//Increment the end index if start has become greater than end
//Print the subarray from index start to end and increment the starting index
void generateSubarraysRecursiveApproach(int *arr, int n, int start, int end)
{
    if(end == n)
    {
        return;
    }
    if(start > end)
    {
        generateSubarraysRecursiveApproach(arr, n, 0, end+1);
    }
    else
    {
        cout << "[";
        for(int i = start; i <= end; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << "]";
        generateSubarraysRecursiveApproach(arr, n, start+1,end);
    }
}