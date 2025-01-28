//Given two strings, check if these two strings are identical(same) or not. 

//Using (==) in C++
bool equalUsingTwoEqualSymbols(string s1, string s2)
{
    return s1 == s2;
}

//Using String Comparison Functions
bool equalUsingStringComparisonFunctions(char[] s1, char[] s2)
{
    return !strcmp(s1, s2);
}

//Writing Your Own Method
bool equalWritingYourOwnMethod(string s1, string s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}




