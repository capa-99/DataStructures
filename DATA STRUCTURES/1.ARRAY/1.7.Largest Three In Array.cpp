//Given an array arr[], the task is to find the top three largest distinct integers present in the array.
//Note: If there are less than three distinct elements in the array, then return the available distinct numbers in descending order.

//Three Traversals
//Find the first largest element by doing one traversal
//Find the second largest by finding the largest element that is not equal to the element found in set 1.
//Find the third largest by finding the largest that is neither equal to first and second.

//One Traversal
//Initialize first, second and third largest elements as -INF (minus infinite). Traverse through the array and handle the following cases for every element x.
//If x is greater than first, update first as x, second as first and third as second.
//Else If x is greater than second and not equal to first, update second as x and third as second
//Else If x is greater third and not equal to first and second, update, third as x.
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector<int> threeLargestOneTraversal(vector<int>& arr)
{
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else
        {
            if(arr[i] > second && arr[i] != first)
            {
                third = second;
                second = arr[i];
            }
            else
            {
                if(arr[i] > third && arr[i] != second && arr[i] != first)
                {
                    third = arr[i];
                }
            }
        }
    }
    vector<int> result;
    if(first == INT_MIN)
    {
        return result;
    }
    result.push_back(first);
    if(second == INT_MIN)
    {
        return result;
    }
    result.push_back(second);
    if(third == INT_MIN)
    {
        return result;
    }
    result.push_back(third);
    return result;
}
//Time Complexity: O(n)
//Auxiliary Space: O(1)