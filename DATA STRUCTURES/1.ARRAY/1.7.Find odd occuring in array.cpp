//Given an array of positive integers, all numbers occur an even number of times except one number which occurs an odd number of times
//Find the number in O(n) time & constant space

#include <iostream> 
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

//A simple solution is to run two nested loops
//The outer loop picks all elements one by one and the inner loop counts the number of occurrences of the element picked by the outer loop
int findOddOccuringUsingNestedLoop(int_array* a)
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
        if(count % 2 != 0)
        {
            return a->arr[i];
        }
    }
    return -1;
}
//Time complexity: O(n²)
//Auxiliary space: O(1)

//A better solution is to use Hashing
//Use array elements as a key and their counts as values
//Create an empty hash table
//One by one traverse the given array elements and store counts
int findOddOccurrenceUsingHashing(int_array* a)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < a->n; i++)
    {
        hash[a->arr[i]]++;
    }
    for(int i = 0; i < a->n; i++)
    {
        if(hash[a->arr[i]] % 2 != 0)
        {
            return a->arr[i];
        }
    }
    return -1;
}
//Time complexity: O(n)
//Auxiliary space: O(n)

//The best solution is to do bitwise XOR of all the elements
//XOR of all elements gives us odd occurring element
//x ⊕ 0 = x
//x ⊕ y = y ⊕ x (Commutative property holds)
//(x ⊕ y) ⊕ z = x ⊕ (y ⊕ z) (Distributive property holds)
//x ⊕ x = 0
int findOddOccurrenceUsingBitManipulation(int_array* a)
{
    int res = 0;
    for(int i = 0; i < a->n; i++)
    {
        res = res ^ a->arr[i];
    }
    return res;
}
//Time complexity: O(n)
//Auxiliary space:O(1)

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
    
    int res = findOddOccuringUsingNestedLoop(&numbers);
    res = findOddOccurrenceUsingHashing(&numbers);
    res = findOddOccurrenceUsingBitManipulation(&numbers);

    print(&numbers);
    cout << res;

    return 0;
}