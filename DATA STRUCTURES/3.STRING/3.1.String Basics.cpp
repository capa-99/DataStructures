//Strings are sequences of characters. The differences between a character array and a string are, a string is terminated with a special character ‘\0’ and strings are typically immutable in most of the programming languages like Java, Python and JavaScript. Below are some examples of strings:
//“geeks” , “for”, “geeks”, “GeeksforGeeks”, “Geeks for Geeks”, “123Geeks”, “@123 Geeks”

//How are Strings represented in Memory?
//In C, a string can be referred to either using a character pointer or as a character array. When strings are declared as character arrays, they are stored like other types of arrays in C. String literals (assigned to pointers) are immutable in C and C++.
//In C++, strings created using string class are mutable and internally represented as arrays.

//How to Declare Strings in various languages?
#include <iostream>
#include <string>
using namespace std;
string s1 = "Hello";
string s2("How are you?");

//Are Strings Mutable in Different Languages?
//In C/C++, string literals (assigned to pointers) are immutable.
//In C++, string objects are mutable.
const char* str = "Hello, world!";
str[0] = 'h';  // Error : Assignment to read only

//General Operations performed on String:
//Length of String
//Search a Character
//Check for Substring
//Insert a Character
//Delete a Character
//Check for Same Strings
//String Concatenation
//Reverse a String
//Rotate a String
//Check for Palindrome