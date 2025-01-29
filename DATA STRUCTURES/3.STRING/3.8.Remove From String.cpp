//Given a string and and a position (0 based), remove the character at the given position.

//Using Built-In Methods
//Use erase in C++.
string removeUsingBuiltInMethods(string s, int pos)
{
    if(pos >= s.length())
    {
        return s;
    }
    s.erase(s.begin() + pos);
    return s;
}

//Writing Your Own Method
//Move all characters after the given position, one index back. To do this, do s[i] = s[i+1] for all indexes i after p.
string removeWritingYourOwnMethod(string s, int pos)
{
    if(pos >= s.length())
    {
        return s;
    }
    for(int i = pos; i < s.length() - 1; i++)
    {
        s[i] = s[i+1];
    }
    s.resize(s.length() - 1);
    return s;
}
//Time Complexity : O(n) where n is the length of input string.
//Auxiliary Space : O(1)