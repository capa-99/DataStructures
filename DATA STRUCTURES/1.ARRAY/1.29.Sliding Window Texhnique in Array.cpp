//Sliding Window problems are problems in which a fixed or variable-size window is moved through a data structure, to solve problems efficiently based on continuous subsets of elements. This technique is used when we need to find subarrays or substrings according to a given set of conditions.

//What is Sliding Window Technique?
//Sliding Window Technique is a method used to efficiently solve problems that involve defining a window or range in the input data and then moving that window across the data to perform some operation within the window. This technique is commonly used in algorithms like finding subarrays with a specific sum, finding the longest substring with unique characters, or solving problems that require a fixed-size window to process elements efficiently.
//Given an array of size N and an integer K, calculate the maximum sum of a subarray having size exactly K.
//One way to do this is by taking each subarray of size K by using Nested loops which will result into O(N2) Time Complexity.
//Can we optimize this approach?
//Instead of taking each K sized subarray and calculating its sum, take one K size subarray from 0 to K-1 index and calculate its sum. Shift the range one by one along with the iterations and update the result
//Instead of recalculating the sum of each K sized subarray we are using previous window of size K to update the sum and shift the window right by moving left and right pointers. This operation is optimal because it takes O(1) time
//This approach of shifting the pointers and calculating the results accordingly is known as Sliding window Technique.

//How to use Sliding Window Technique?
//There are two types of sliding window:
//1. Fixed Size Sliding Window:
//Find the size of the window required, K.
//Compute the result for 1st window
//Use a loop to slide the window by 1 and keep computing the result window by window.
//2. Variable Size Sliding Window:
//Increase the right pointer one by one until the condition is true.
//At any step, if the condition does not match, shrink the size of the window by increasing the left pointer.
//When the condition is true, start increasing the right pointer and follow step 1.
//Follow these steps until the end of the array is reached.

//How to Identify Sliding Window Problems:
//These problems generally require Finding Maximum/Minimum Subarray, Substrings which satisfy some specific condition.
//The size of the subarray or substring ‘K’ will be given in some of the problems.
//These problems can easily be solved in O(N2) time complexity using nested loops,but  using sliding window the time complexity is O(n) 
//Required Time Complexity: O(N) or O(Nlog(N))
//Constraints: N <= 106 , If N is the size of the Array/String.

//Use Cases of Sliding Window Technique:
//1. To find the maximum sum of all subarrays of size K:
//Given an array of integers of size ‘n’, calculate the maximum sum of ‘k’ consecutive elements in the array.
//Naive Approach: Brute Force Approach. Start with the first index and sum until the kth element. Do this for all possible consecutive blocks or groups of k elements. This method requires a nested for loop, the outer for loop starts with the starting element of the block of k elements, and the inner or the nested loop will add up till the kth element.
#include <climits>
using namespace std;
int findMaxKSumNaiveSpproach(int *arr, int n, int k)
{
    int max = INT_MIN;
    for(int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for(int j = i; j < i+k; j++)
        {
            sum = sum + arr[j];
        }
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}
//Time complexity: O(k*n) as it contains two nested loops.
//Auxiliary Space: O(1)
//Applying the sliding window technique: 
//Compute the sum of the first k elements out of n terms using a linear loop and store the sum in variable window_sum.
//Traverse linearly over the array until it reaches the end and simultaneously keep track of the maximum sum.
//To get the current sum of a block of k elements  subtract the first element from the previous block and add the last element of the current block.
int findMaxKSumSlidingWindowTechnique(int *arr, int n, int k)
{
    int sum = 0;
    int max;
    for(int i = 0; i < k; i++)
    {
        sum = sum + arr[i];
    }
    max = sum;
    for(int i = 0; i <= n-k; i++)
    {
        sum = sum - arr[i] + arr[i+k];
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}
//Time Complexity: O(n), where n is the size of input array arr[].
//Auxiliary Space: O(1)
//2. Smallest subarray with sum greater than a given value:
//Given an array arr[] of integers and a number X, find the smallest subarray with a sum greater than the given value.
//Approach:
//Solve this problem using Sliding Window Technique and maintaining two pointers: start and end to mark the starting and ending of the window. Keep incrementing the end pointer until the sum of the window is less than or equal to X. When the sum of window becomes greater than X, record the length of the window and start moving the start pointer until the sum of window becomes smaller than or equal to X. Again start incrementing the end pointer. Keep on moving the start and end pointer until the end of the array is reached.
//3. Find subarray with given sum in an array of non-negative integers:
//Given an array arr[] of non-negative integers and an integer sum, find a subarray that adds to a given sum.
//Approach:
//If a subarray has sum greater than the given sum then there is no possibility that adding elements to the current subarray will be equal to the given sum. So the Idea is to use a similar approach to a sliding window. 
//Start with an empty subarray.
//add elements to the subarray until the sum is less than x. 
//If the sum is greater than x, remove elements from the start of the current subarray.
//4. Smallest window that contains all characters of string itself:
//Approach:
//A window of characters is maintained by using two pointers start and end. Whenever the window contains all characters of given string, the window is shrinked from left side to remove extra characters and then its length is compared with the smallest window found so far. 
//If no more characters can be deleted then start increasing the size of the window using the end until all the distinct characters are present in the window. Find the minimum size