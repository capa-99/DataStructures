//Given a string str and an array of indices chars[] that describes the indices in the original string where the characters will be added. The characted needed to be inserted is star (*). Each star should be inserted before the character at the given index. Return the modified string after the stars have been added.
//Approach:
//Iterate over the string and keep track of the count of the characters in the string so far and whenever the count becomes equal to the element in the array of stars, append a star to the resultant string and move ahead in the star array.
//Create a string ans for storing the resultant string.
//Take one pointer j initially as 0.
//Iterate over the string and whenever the index that represents the count of characters becomes equal to the element in stars[j], append the star in the ans string and move the j pointer ahead.
//At each move, append the current character in the ans string.
string insertMultiple(string s, int pos[], int n)
{
    int j = s.length() - 1;
    s.resize(s.length() + n);
    int i = s.length() - 1;
    int k = n - 1;
    while(i >= 0)
    {
        s[i] = s[j];
        if(k >= 0)
        {
            if(j == pos[k])
            {
                i--;
                s[i] = '*';
                k--;
            }
        }
        i--;
        j--;
    }
    return s;
}
//Time Complexity: O(N)
//Auxiliary Space: O(N)

//Approach: using inbuilt insert function.
//Increase the length of orignal string by 1, as the insert operation adds 1 character.
//Iterate through the stars vector using a for loop.
//For each position specified in the stars vector, insert an asterisk (*) at that position in the string s(using insert function).
//Increment k on insertion because the size increases
//Return the updated string
string insertMultipleUsingInbuiltInsertFunction(string s, int pos[], int n)
{
    int j = s.length() - 1;
    int k = n - 1;
    while(k >= 0)
    {
        if(j == pos[k])
        {
            s.insert(s.begin() + pos[k], '*');
            k--;
        }
        j--;
    }
    return s;
}
//Time Complexity: O(N*K)
//Auxiliary Space: O(N)
//Explaination:
//The time complexity of this approach is O(n*k), where n is the length of the string and k is the size of the vector. This is because for each position in the vector, we need to insert an asterisk into the string, which takes O(n) time.
//The auxiliary space complexity is O(1), as there are no additional data structures used.