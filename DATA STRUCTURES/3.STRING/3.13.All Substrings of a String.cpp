//Given a string as an input, print all non-empty substrings of that given string
//We mainly use two nested loops
//Outermost Loop : Picks starting index of current subarray
//Inner Loop : Picks ending point of current subarray and prints the subarray using substring function.
#include <iostream>
#include <string>
using namespace std;
void printAllSubstrings(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            cout << s.substr(i, j - i) << ", ";
        }
    }
}
//Time Complexity : O(n^3) Note that there are two nested loops and a substr function which also takes O(n) time.