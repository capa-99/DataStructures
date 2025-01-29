//Given a string s, a character c and an integer position pos, the task is to insert the character c into the string s at the specified position pos.

//Using Built-In Methods
//Use library methods like string insert in C++.
#include <iostream>
using namespace std;
string insertUsingBuiltInMethods(string s, char c, int pos)
{
    if(pos >= s.length())
    {
        return s;
    }
    s.insert(s.begin() + pos, c);
    return s;
}
//Time Complexity: O(n) where n is the length of the string.

//Using Custom Method
//Iterate through the given string, inserting all the characters into a new string until the position where the given character needs to be inserted is reached. At that position, insert the character, and then append the remaining characters from the input string to the new string.
string insertUsingCustomMethod(string s, char c, int pos)
{
    if(pos >= s.length())
    {
        return s;
    }
    s.resize(s.length() + 1);
    for(int i = s.length()-1; i > pos; i--)
    {
        s[i] = s[i-1];
    }
    s[pos] = c;
    return s;
}
//Time Complexity: O(n) where n is the length of the string.