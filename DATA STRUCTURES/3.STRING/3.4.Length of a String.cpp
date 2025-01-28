//Given a string s, the task is to find the length of the string.

//Using In-built methods
//Every programming language offers a built-in method as well to find the length
#include <iostream>
#include <string>
using namespace std;
int lengthUsingInbuiltMethods(string s)
{
    return s.length();
}
//Programming Language  In-Built method to find the length of the string
//C                     strlen()
//C++                   size()

//Writing your Method
//The most traditional method of finding the length of the string is by traversing each character through the loop.
//Using a counter, traverse each character of the string with the help of Loop.
//Return the counter value as the length of the string.
int lengthWritingYourMethod(string s)
{
    char c = s[0];
    int i = 0;
    while (c != '\0')
    {
        i++;
        c = s[i];
    }
    return i;
}
//Time Complexity: O(n), where n is the length of the string.
//Auxiliary space: O(1)