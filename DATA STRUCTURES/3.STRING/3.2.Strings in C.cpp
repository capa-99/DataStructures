//A String in C programming is a sequence of characters terminated with a null character ‘\0’. The C String is stored as an array of characters. The difference between a character array and a C string is that the string in C is terminated with a unique character ‘\0’.

//C String Declaration Syntax
//Declaring a string in C is as simple as declaring a one-dimensional array.
//char string_name[size];
//In the above syntax string_name is any name given to the string variable and size is used to define the length of the string, i.e the number of characters strings will store.
//There is an extra terminating character which is the Null character (‘\0’) used to indicate the termination of a string that differs strings from normal character arrays.

//C String Initialization
//A string in C can be initialized in different ways. 
//We can initialize a C string in 4 different ways which are as follows:
//1. Assigning a String Literal without Size
//String literals can be assigned without size. Here, the name of the string str acts as a pointer because it is an array.
char str[] = "GeeksforGeeks";
//2. Assigning a String Literal with a Predefined Size
//String literals can be assigned with a predefined size. Always account for one extra space which will be assigned to the null character. If we want to store a string of size n  always declare a string with a size equal to or greater than n+1.
char str[50] = "GeeksforGeeks";
//3. Assigning Character by Character with Size
//The string can also be assigned character by character. Remember to set the end character as ‘\0’ which is a null character.
char str[14] = { 'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};
//4. Assigning Character by Character without Size
//Assign character by character without size with the NULL character at the end. The size of the string is determined by the compiler automatically.
//char str[] = { 'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};
//Note: When a Sequence of characters enclosed in the double quotation marks is encountered by the compiler, a null character ‘\0’ is appended at the end of the string by default.

#include <stdio.h>
#include <string.h>
char str[] = "Geeks";
printf("%s\n", str);
printf("Length of string str is %d", strlen(str));
//Strings can be printed using normal printf statements just like any other variable. Unlike arrays, string doesn't need to be printed character by character.
//Note: The C language does not provide an inbuilt data type for strings but it has an access specifier “%s” which can be used to print and read strings directly. 

//Read a String Input From the User
//Take string input using scanf() function in C
// C program to read string from user
char str[50];
scanf("%s",str);
printf("%s",str);
//The string can also be read using a single scanf statement.
//The ‘&’ sign is used to provide the address of the variable to the scanf() function to store the value read in memory. As str[] is a character array using str without braces ‘[‘ and ‘]’ will give the base address of this string. That’s why ‘&’ is not used in this case as the base address of the string is already provided to scanf.
//The string is read only till the whitespace is encountered.
//Note: After declaration, if we want to assign some other text to the string, we have to assign it one by one or use the built-in strcpy() function because the direct assignment of the string literal to character array is only possible in declaration.

//How to Read a String Separated by Whitespaces in C?
//The two common methods are:
//Use the fgets() function to read a line of string and gets() to read characters from the standard input (stdin) and store them as a C string until a newline character or the End-of-file (EOF) is reached.
//Scanset characters inside the scanf() function
//1. String Input using gets()
char str[50];
fgets(str, MAX, stdin);
printf("String is: \n");
puts(str);
//2. String Input using scanset
char str[20];
scanf("%[^\n]s", str);
printf("%s", str);

//C String Length
//The length of the string is the number of characters present in the string except for the NULL character. Easily find the length of the string using the loop to count the characters from the start till the NULL character is found.

//Passing Strings to Function
//As strings are character arrays, they can be passed to functions in the same way as arrays are passed to a function. 
void printString(char str[]) 
{ 
    printf("String is: %s", str); 
}
char str[] = "GeeksforGeeks";
printStr(str);
//Note: We can’t read a string value with spaces, but use either gets() or fgets() in the C programming language.

//Strings and Pointers in C
//In Arrays, the variable name points to the address of the first element.
//Similar to arrays, In C, we can create a character pointer to a string that points to the starting address of the string which is the first character of the string. The string can be accessed with the help of pointers as shown in the below example. 
char str[20] = "GeeksforGeeks";
char* ptr = str;
while (*ptr != '\0') 
{
    printf("%c", *ptr);
    ptr++;
}

//Standard C Library – String.h  Functions
//The C language comes bundled with <string.h> which contains some useful string-handling functions. Some of them are as follows:
//Function Name	        Description
//strlen(string_name)	Returns the length of string name.
//strcpy(s1, s2)	    Copies the contents of string s2 to string s1.
//strcmp(str1, str2)	Compares the first string with the second string. If strings are the same it returns 0.
//strcat(s1, s2)	    Concat s1 string with s2 string and the result is stored in the first string.
//strlwr()	            Converts string to lowercase.
//strupr()	            Converts string to uppercase.
//strstr(s1, s2)	    Find the first occurrence of s2 in s1.