//C++ strings are sequences of characters stored in a char array. Strings are used to store words and text. They are also used to store data, such as numbers and other types of information. Strings in C++ can be defined either using the std::string class or the C-style character arrays.

//1. C Style Strings
//These strings are stored as the plain old array of characters terminated by a null character ‘\0’. They are the type of strings that C++ inherited from C language.
//Syntax:
//char str[] = "GeeksforGeeks";
//Understanding how to work with strings is fundamental in C++. 
char s[] = "String";

//2. std::string Class
//These are the new types of strings that are introduced in C++ as std::string class defined inside <string> header file. This provides many advantages over conventional C-style strings such as dynamic size, member functions, etc.
//Syntax:
//std::string str("GeeksforGeeks");
#include <string>
using namespace std;
string str("String");
//One more way we can make strings that have the same character repeating again and again.
//Syntax:
//std::string str(number,character);
string rep(5, 'r');

//Ways to Define a String in C++
//Strings can be defined in several ways in C++. Strings can be accessed from the standard library using the string class. Character arrays can also be used to define strings. String provides a rich set of features, such as searching and manipulating, which are commonly used methods. Ways to define a string in C++ are:
//Using String keyword
//Using C-style strings
//1. Using string Keyword
//It is more convenient to define a string with the string keyword instead of using the array keyword because it is easy to write and understand.
//Syntax:
//string s = "GeeksforGeeks";
//string s("GeeksforGeeks");
string s = "GeeksforGeeks";
string str("GeeksforGeeks");
//2. Using C-style strings
//Using C-style string libraries functions such as strcpy(), strcmp(), and strcat() to define strings. This method is more complex and not as widely used as the other two, but it can be useful when dealing with legacy code or when you need performance.
//char s[] = {'g', 'f', 'g', '\0'};
//char s[4] = {'g', 'f', 'g', '\0'};
//char s[4] = "gfg";
//char s[] = "gfg";
//2. Using C-style strings
//Using C-style string libraries functions such as strcpy(), strcmp(), and strcat() to define strings. This method is more complex and not as widely used as the other two, but it can be useful when dealing with legacy code or when you need performance.
//char s[] = {'g', 'f', 'g', '\0'};
//char s[4] = {'g', 'f', 'g', '\0'};
//char s[4] = "gfg";
//char s[] = "gfg";
char s1[] = { 'g', 'f', 'g', '\0' };
char s2[4] = { 'g', 'f', 'g', '\0' };
char s3[4] = "gfg";
char s4[] = "gfg";

//How to Take String Input in C++
//String input means accepting a string from a user. In C++ there are different types of taking input from the user which depend on the string. The most common way is to take input with cin keyword with the extraction operator (>>) in C++. Methods to take a string as input are:
//cin
//getline
//stringstream
//1. Using Cin
//The simplest way to take string input is to use the cin command along with the stream extraction operator (>>). 
//Syntax:
//cin>>s;
cin >> s;
//2. Using getline 
//The getline() function in C++ is used to read a string from an input stream. It is declared in the <string> header file.
//Syntax:
//getline(cin,s);
getline(cin, s);
//3. Using stringstream
//The stringstream class in C++ is used to take multiple strings as input at once. 
//Syntax:
//stringstream stringstream_object(string_name);
#include <sstream>
string s = "Hello World";
stringstream str(s);

//How to Pass Strings to Functions?
//In the same way that we pass an array to a function, strings in C++ can be passed to functions as character arrays.
void print_string(string s)
{
    cout << "Passed String is: " << s << endl;
    return;
}
string s = "Pass me to a function";
print_string(s);

//Pointers and Strings
//Pointers in C++ are symbolic representations of addresses. They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures. By using pointers we can get the first character of the string, which is the starting address of the string. The given string can be accessed and printed through the pointers.
char* p = &s[0];
while (*p != '\0') 
{
    cout << *p;
    p++;
}

//Difference between String and Character array in C++
//The main difference between a string and a character array is that strings are immutable, while character arrays are not.
//String                                                                    Character Array
//Strings define objects that can be represented as string streams.         The null character terminates a character array of characters.
//No Array decay occurs in strings as strings are represented as objects.   The threat of array decay is present in the case of the character array 
//A string class provides numerous functions for manipulating strings.	    Character arrays do not offer inbuilt functions to manipulate strings.
//Memory is allocated dynamically.	                                        The size of the character array has to be allocated statically. 

//C++ String Functions
//C++ provides some inbuilt functions which are used for string manipulation, such as the strcpy() and strcat() functions for copying and concatenating strings.
//Function      Description
//length()	    This function returns the length of the string.
//swap() 	    This function is used to swap the values of 2 strings.
//size() 	    Used to find the size of string
//resize()	    This function is used to resize the length of the string up to the given number of characters.
//find()	    Used to find the string which is passed in parameters
//push_back()	This function is used to push the passed character at the end of the string
//pop_back() 	This function is used to pop the last character from the string
//clear() 	    This function is used to remove all the elements of the string.
//strncmp()	    This function compares at most the first num bytes of both passed strings.
//strncpy()	    This function is similar to strcpy() function, except that at most n bytes of src are copied
//strrchr()	    This function locates the last occurrence of a character in the string.
//strcat()	    This function appends a copy of the source string to the end of the destination string
//find()	    This function is used to search for a certain substring inside a string and returns the position of the first character of the substring. 
//replace()	    This function is used to replace each element in the range [first, last) that is equal to old value with new value.
//substr()	    This function is used to create a substring from a given string. 
//compare()	    This function is used to compare two strings and returns the result in the form of an integer.
//erase()	    This function is used to remove a certain part of a string.
//rfind()       This function is used to find the string’s last occurrence.

//C++ Strings iterator functions 
//In C++ inbuilt string iterator functions provide the programmer with an easy way to modify and traverse string elements. These functions are:
//Functions	Description
//begin()	This function returns an iterator pointing to the beginning of the string.
//end()	    This function returns an iterator that points to the end of the string.
//rbegin()	This function returns a reverse iterator pointing to the end of the string. 
//rend()	This function returns a reverse iterator pointing to the beginning of the string.
//cbegin()	This function returns a const_iterator pointing to the beginning of the string.
//cend() 	This function returns a const_iterator pointing to the end of the string.
//crbegin() This function returns a const_reverse_iterator pointing to the end of the string.
//crend()	This function returns a const_reverse_iterator pointing to the beginning of the string.
string::iterator itr;
string::reverse_iterator ritr;
string s = "Hello";
itr = s.begin();
itr = s.end() - 1;
ritr = s.rend() - 1;

//String Capacity Functions
//In C++, string capacity functions are used to manage string size and capacity. Primary functions of capacity include:
//Function	        Description
//length()	        This function is used to return the size of the string
//capacity()	    This function returns the capacity which is allocated to the string by the compiler
//resize()	        This function allows us to increase or decrease the string size
//shrink_to_fit()   This function decreases the capacity and makes it equal to the minimum.
s.length();
s.capacity();
s.resize(10);
s.resize(20);
s.shrink_to_fit();

//The string class provides more advanced features, while the character array provides basic features but is efficient and easy to use.