//Two pointers is really an easy and effective technique that is typically used for Two Sum in Sorted Arrays, Closest Two Sum, Three Sum, Four Sum, Trapping Rain Water and many other. Given a sorted array arr (in ascending order) and a target, find if there exists any pair of elements (arr[i], arr[j]) such that their sum is equal to the target.

//Naive Method – O(n^2) Time and O(1) Space
//Generate all the possible pairs and check if any of them add up to the target value. To generate all pairs, run two nested loops.
bool findTargetPairsNaive(int *arr, int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

//Better Approaches – Binary Search and Hashing
//These methods give better time complexity but Two Pointer Technique is the best solution 

//Two-Pointer Technique – O(n) time and O(1) space
//Begin with two corners of the given array. Use two index variables left and right to traverse from both corners.
//Initialize: left = 0, right = n – 1
//Run a loop while left < right and do the following inside the loop
//Compute current sum, sum = arr[left] + arr[right]
//If the sum equals the target, the pair is found.
//If the sum is less than the target, move the left pointer to the right to increase the sum.
//If the sum is greater than the target, move the right pointer to the left to decrease the sum.
bool findTargetPairsTwoPointerTechnique(int *arr, int n, int target)
{
    int left = 0, right = n - 1;
    while(left < right)
    {
        if(arr[left] + arr[right] == target)
        {
            return true;
        }
        if(arr[left] + arr[right] < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}
//Time Complexity: O(n) as the loops runs at most n times.
//Auxiliary Space: O(1)

//How does this work?
//We need to prove that we never miss a valid pair.
//Case 1 ( When we increment left ) In this case we simply ignore current arr[left] and move to the next element by doing left++. We do this when arr[left] + arr[right] is smaller than the target. The reason this step is safe is, if arr[left] is giving a smaller value than sum, then it will give even lesser values for the elements before arr[right].
//Case 2 (When we decrement right) We can use the same reasoning to prove that we never miss out a valid pair.