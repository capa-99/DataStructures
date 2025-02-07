//String concatenation is the process of joining two strings end-to-end to form a single string.

//Using + Operator
//Almost all languages support + operator to concatenate two strings. In C, there is a library function strcat() for the same purpose.
#include <iostream>
#include <string>
using namespace std;
string concatenateUsingPlusOperator(string s1, string s2)
{
    return s1 + s2;
}

//Write your Own Method
//Create an empty result string.
//Traverse through s1 and append all characters to result.
//Traverse through s2 and append all characters to result.
string concatenateWriteYourOwnMethod(string s1, string s2)
{
    int prev = s1.size();
    s1.resize(prev + s2.size());
    for(int i = prev; i < s1.size(); i++)
    {
        s1[i] = s2[i-prev];
    }
    return s1;
}
//Time Complexity : O(m + n) where m and n are lengths of the two strings.