//Given a character ch and a string s, find the index of first occurrence of the character in the string. If the character is not present in the string, return -1

//By traversing the string - O(n) Time and O(1) Space
//The idea is to traverse the input string s and for each character, check if it is equal to the character we are searching for. If we find a match, return the index of the current character. 
//If we reach the end of the string without finding any occurrence of the character, return -1.
#include <iostream>
using namespace std;
int searchByTraversingTheString(string s, char c)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            return i;
        }
    }
    return -1;
}

//Using in-built library functions - O(n) Time and O(1) Space
//Use inbuilt library functions to search for a character in a string. This makes the search simple and easier to implement.
int searchUsingInbuiltLibraryFunctions(string s, char c)
{
    return s.find(c);
}