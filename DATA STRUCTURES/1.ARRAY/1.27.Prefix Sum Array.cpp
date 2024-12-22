//Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].
//Approach:
//Declare a new array prefixSum[] of the same size as the input array
//Run a for loop to traverse the input array
//For each index add the value of the current element and the previous value of the prefix sum array
void findPrefixSum(int *arr, int *prefixSum, int n)
{
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
}
//Time Complexity: O(N)
//Auxiliary Space: O(N)

//Sum of an array between indexes L and R using Prefix Sum:
//Given an array arr[] of size N and given Q queries and in each query given L and R, Print the sum of array elements from index L to R.
//Create the prefix sum array of the given input array
//For every query
//If L is greater than 1, then print prefixSum[R] – prefixSum[L-1]
//else print prefixSum[R]
struct query
{  
    int L;
    int R;
};
void prefixSumLR(int *arr, query *q, int n, int m)
{
    for(int i = 0; i < m; i++)
    {
        if(q[i].L < 0)
        {
            int sum = 0;
            for(int j = 0; j <= q[i].R; j++)
            {
                sum = sum + arr[j];
                cout << sum << ", ";
            }
        }
        else
        {
            int sum = 0;
            for(int j = q[i].L; j <= q[i].R; j++)
            {
                sum = sum + arr[j];
                cout << sum << ", ";
            }
        }
        cout << endl;
    }
}
//Time Complexity: O(N)
//Auxiliary Space: O(N)

//Example Problem: 
//Consider an array of size N with all initial values as 0. Perform the given ‘m’ add operations from index ‘a’ to ‘b’ and evaluate the highest element in the array. An add operation adds 100 to all the elements from a to b (both inclusive). 

//Naive Approach:
//Run a loop ‘m’ times, inputting a and b and running a loop from a to b, adding all elements by 100. 
//Time Complexity: O(N * M)
//Auxiliary Space: O(1)

//Efficient Approach:
//Use Prefix Sum Array
//Run a loop for ‘m‘ times, inputting ‘a‘ and ‘b‘.
//Add 100 at index ‘a‘ and subtract 100 from index ‘b+1‘.
//After completion of ‘m‘ operations, compute the prefix sum array.
//Scan the largest element
//Explanation: We added 100 at ‘a’ because this will add 100 to all elements while taking the prefix sum array. Subtracting 100 from ‘b+1’ will reverse the changes made by adding 100 to elements from ‘b’ onward.
int exampleProblem(int *arr, query* op, int n, int m)
{
    for(int i = 0; i < m; i++)
    {
        arr[op[i].L] = arr[op[i].L] + 100;
        arr[op[i].R+1] = arr[op[i].R+1] - 100;
    }
    int *prefix = new int[n];
    findPrefixSum(arr,prefix,n);
    int max = -100000000;
    for(int i = 0; i < n; i++)
    {
        if(prefix[i] > max)
        {
            max = prefix[i];
        }
    }
    return max;
}
//Time Complexity: O(N + M), where N is the size of the array and M is the number of operations
//Auxiliary Space: O(N)

//Applications of Prefix Sum: 
//Equilibrium index of an array:  an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
//Find if there is a subarray with 0 sums
//Maximum subarray size, such that all subarrays of that size have a sum less than k
//Find the prime numbers which can be written as sum of most consecutive primes
//Longest Span with same Sum in two Binary arrays
//Maximum subarray sum modulo m
//Maximum occurred integer in n ranges
//Minimum cost for acquiring all coins with k extra coins allowed with every coin
//Random number generator in arbitrary probability distribution fashion