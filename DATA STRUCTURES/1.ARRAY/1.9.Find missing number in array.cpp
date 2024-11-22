//Given an array arr[] of iz n - 1 with integers in the range of [1, n], find the missing number from the first N integers
//Note: there are no duplicates in the list

#include <iostream> 
#include <climits>
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

//O(n) time and O(n) space
//The vvery basic idea is to use an array to store the frequency of each element in the given array
//The number with a frequency of 0 is the missing number
int findMissingNumberUsingHashing(int_array* a)
{
    int_array tmp;
    tmp.arr = new int(a->n + 1);
    tmp.n = a->n + 1;
    for(int i = 0; i < tmp.n; i++)
    {
        tmp.arr[i] = 0;
    }
    for(int i = 0; i < a->n; i++)
    {
        tmp.arr[a->arr[i] - 1]++;
    }

    for(int i = 1; i < tmp.n; i++)
    {
        if(tmp.arr[i] == 0)
        {
            return i + 1;
        }
    }
    return -1;
}

//O(n) time and O(1) auxiliary space
//An efficient approach is to use summation formula
//The sum of the first N natural numbers is given by the formula N*(N+1)/2
//Compute the sum and substract the sum of all elements in the array from it to get the missing number
int findMissingNumberUsingSumOfNTermsFormula(int_array* a)
{
    int sum = ((a->n + 2) * (a->n + 1)) / 2;
    for(int i = 0; i < a->n; i++)
    {
        sum = sum - a->arr[i];
    }
    return sum;
}

//O(n) time nd O(1) auxiliary space
//Another efficient approach is to use the XOR operation
//XOR of a number with itself is 0, and XOR of a number with 0 is the nuber itself
//If we find XOR of first N natural numbers and then take XOR of eaxh array elements with this, then the resultant will be the missing number
int findMissingNumberUsingXOROperation(int_array* a)
{
    int xornum = 0, xorsum = 0;
    for(int i = 0; i < a->n; i++)
    {
        xornum = xornum ^ a->arr[i];
        xorsum = xorsum ^ i;
    }
    xorsum = xorsum ^ a->n ^ (a->n + 1);
    return xornum ^ xorsum;
}


int main()
{
    int_array numbers;
    numbers.n = 5;
    numbers.arr = new int[15];
    numbers.arr[0] = 1;
    numbers.arr[1] = 6;
    numbers.arr[2] = 2;
    numbers.arr[3] = 4;
    numbers.arr[4] = 3;
    
    int res = findMissingNumberUsingHashing(&numbers);
    res = findMissingNumberUsingSumOfNTermsFormula(&numbers);
    res = findMissingNumberUsingXOROperation(&numbers);

    print(&numbers);
    cout << res;

    return 0;
}