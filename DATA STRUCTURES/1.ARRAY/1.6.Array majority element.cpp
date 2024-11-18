//Given an array arr find the majority element in the array
//If no majority exists, return -1
//A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array

#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct int_array
{
    int* arr;
    int n;
};

void print(int_array* a)
{
    for(int i = 0; i < a->n; i++)
    {
        cout << a->arr[i] << " ";
    }
}

//The idea is to count the frequency of each element using nested loops
//The first loop iterates through each element of the array, treating it as a majority element
//For each element, the second loop counts its occurences in the entire array
//After the second loop, check if this element appears more than n/2 times, where n is the size of the array and if it does, it's the majority element in the array
int findMajorityUsingTwoNestedLoops(int_array* a)
{
    for(int i = 0; i < a->n; i++)
    {
        int count = 0;
        for(int j = 0; j < a->n; j++)
        {
            if(a->arr[i] == a->arr[j])
            {
                count++;
            }
        }
        if(count > a->n/2)
        {
            return a->arr[i];
        }
    }
    return -1;
}
//Time complexity: O(n²)
//Auxiliary space: O(1)

//The idea is to sort the array and go through it while keeping track of how many times each element appears
//When a new element is encounteres, check if the count of the previous element was more than half the total number of elements in the array
//If it was, that element is the majority and should be returned
//If no element meets this requirement, no majority element exists
int findMajorityUsingSorting(int_array* a)
{
    vector<int> temp;
    for(int i = 0; i <a->n; i++)
    {
        temp.push_back(a->arr[i]);
    }
    sort(temp.begin(), temp.end());
     for(int i = 0; i <a->n; i++)
    {
        a->arr[i] = temp[i];
    }
    
    if(a->n == 1)
    {
        return a->arr[0];
    }
    int count = 1;
    for(int i = 0; i < a->n - 1; i++)
    {
        if(a->arr[i] == a->arr[i+1])
        {
            count++;
        }
        else
        {
            if(count > a->n / 2)
            {
                return a->arr[i];
            }
            else
            {
                count = 1;
            }
        }
    }
    if(count > a->n / 2)
    {
        return a->arr[a->n-1];
    }
    return -1;
}
//time complexity: O(n*log(n))
//Auxiliary space: O(1)

//The idea is to use a hashmap to count the occurences of each element in the array
//Traverse the array once, and for each element update its count in the hashmap
//After updating the count, check if ount exceeds n/2
//If such element is found, return it
//If no element's count exceeds n/2 return -1
int findMajorityUsingHashing(int_array* a)
{
    unordered_map<int, int> counts;
    for(int i = 0; i < a->n; i++)
    {
        counts[a->arr[i]]++;
        if(counts[a->arr[i]] > a->n / 2)
        {
            return a->arr[i];
        }
    }
    return -1;
}
//Time complexity: O(n)
//Auxiliary space:O(n)

//the first step gives the element that may be the majority element int the array
//The element given is a majority element if there is one in the array, if there isn't oe, the element given is just a candidtate ad it's irrelevant
//Check if thi element from the above step is the majority element
//First, initialize a candidate variable and a count variable
//Travere the array once
//If count is zero, set the candidate to the current element and set count to one
//If the current element equals the candidate, increment count
//If the current element differs from the candidate, decrement count
//Traverse the array again to count the occurences of the candidate and if its count is greater than n/2 return it
int findMajorityUsingMooresVotingAlgorithm(int_array* a)
{
    int candidate = -1;
    int count = 0;
    for(int i = 0; i < a->n; i++)
    {
        if(count == 0)
        {
            candidate = a->arr[i];
            count = 1;
        }
        else
        {
            if(candidate == a->arr[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
    }
    count = 0;
    for(int i = 0; i < a->n; i++)
    {
        if(a->arr[i] == candidate)
        {
            count++;
        }
    }
    if(count > a->n / 2)
    {
        return candidate;
    }
    return -1;
}
//Time complexity: O(n)
//Auxiliary space O(1)

int main()
{
    int_array numbers;
    numbers.n = 5;
    numbers.arr = new int[15];
    numbers.arr[0] = 1;
    numbers.arr[1] = 5;
    numbers.arr[2] = 5;
    numbers.arr[3] = 3;
    numbers.arr[4] = 1;
    
    int majority = findMajorityUsingTwoNestedLoops(&numbers);
    majority = findMajorityUsingSorting(&numbers);
    majority = findMajorityUsingHashing(&numbers);
    majority = findMajorityUsingMooresVotingAlgorithm(&numbers);

    print(&numbers);
    cout << majority;

    return 0;
}