//Given an array arr[] of size n, find all the Leaders in the array. An element is a Leader if it is greater than all the elements to its right side.
//Note: The rightmost element is always a leader.

//Using Nested Loops – O(n^2) Time and O(1) Space:
//Use two loops. The outer loop runs from 0 to size – 1 and one by one pick all elements from left to right. The inner loop compares the picked element to all the elements on its right side. If the picked element is greater than all the elements to its right side, then the picked element is the leader.
#include <vector>
#include <algorithm>
using namespace std;
vector<int> leadersUsingNestedLoops(vector<int>& arr)
{
    vector<int> leaders;
    for(int i = 0; i < arr.size(); i++)
    {
        int j = i + 1;
        while(j < arr.size() && arr[j] < arr[i])
        {
            j++;
        }
        if(j == arr.size())
        {
            leaders.push_back(arr[i]);
        }
    }
    return leaders;
} 

//Using Suffix Maximum – O(n) Time and O(1) Space:
//The idea is to scan all the elements from right to left in an array and keep track of the maximum till now. When the maximum changes its value, add it to the result. Finally reverse the result 
vector<int> leadersUsingSuffixMaximum(vector<int>& arr)
{
    vector<int> leaders;
    int max = arr[arr.size()-1];
    leaders.push_back(max);
    for(int i = arr.size() - 2; i >= 0; i--)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            leaders.push_back(max);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}