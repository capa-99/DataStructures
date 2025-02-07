//Given a string s, reverse the string. Reversing a string means rearranging the characters such that the first character becomes the last, the second character becomes second last and so on.

//Using backward traversal – O(n) Time and O(n) Space
//Start at the last character of the string and move backward, appending each character to a new string res. This new string res will contain the characters of the original string in reverse order.
string reverseUsingBackwardTraversal(string s)
{
    string res;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        res = res + s[i];
    }
    return res;
}
//Time Complexity: O(n) for backward traversal
//Auxiliary Space: O(n) for storing the reversed string.

//Using Two Pointers – O(n) Time and O(n) Space
//Maintain two pointers: left and right, such that left points to the beginning of the string and right points to the end of the string. 
//While left pointer is less than the right pointer, swap the characters at these two positions. After each swap, increment the left pointer and decrement the right pointer to move towards the center of the string. This will swap all the characters in the first half with their corresponding character in the second half.
string reverseUsingTwoPointers(string s)
{
    int left = 0, right = s.size() - 1;
    while(left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return s;
}
//Time Complexity: O(n) 
//Auxiliary Space: O(n)

//Using Recursion – O(n) Time and O(n) Space
//Use recursion and define a recursive function that takes a string as input and reverses it. Inside the recursive function, 
//Swap the first and last element. 
//Recursively call the function with the remaining substring.
string recursive(string s, int left, int right)
{
    if(left > right)
    {
        return s;
    }
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    s = recursive(s, left + 1, right - 1);
    return s;
}
string reverseUsingRecursion(string s)
{
    s = recursive(s, 0, s.size() - 1);
    return s;
}
//Time Complexity: O(n) where n is length of string
//Auxiliary Space: O(n)

//Using Stack – O(n) Time and O(n) Space
//Use stack for reversing a string because Stack follows Last In First Out (LIFO) principle. This means the last character addd is the first one to be taken out. When all the characters of a string are pushed into the stack, the last character becomes the first one to pop. 
#include <stack>
string reverseUsingStack(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++) 
    {
        st.push(s[i]);
    }
    for (int i = 0; i < s.size(); i++) 
    {
        s[i] = st.top();
        st.pop();
    }
    return s;
}
//Time Complexity: O(n) 
//Auxiliary Space: O(n)

//Using Inbuilt methods – O(n) Time and O(1) Space
//Use built-in reverse method to reverse the string. 
string reverseUsingInbuiltMethod(string s)
{
    reverse(s.begin(), s.end());
    return s;
}