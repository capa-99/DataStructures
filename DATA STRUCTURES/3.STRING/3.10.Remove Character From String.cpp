//Given a string and a character, remove all the occurrences of the character in the string.

//Using Built-In Methods
#include <algorithm>
#include <iostream>
using namespace std;
string removeCharUsingBuiltInMethods(string str, char c) 
{
    str.erase(remove(str.begin(), str.end(), c), str.end());
    return str;
}

//Writing Your Own Method
//Maintain an index of the resultant string.  
string removeCharWritingYourOwnMethod(string str, char c)
{
    int i = 0, j = 0;
    while(str[i] != '\0')
    {
        if(str[i] == c)
        {
            i++;
        }
        str[j] = str[i];
        i++;
        j++;
    }
    str.resize(j);
    return str;
}
//Time Complexity : O(n) where n is length of input string.
//Auxiliary Space : O(1)