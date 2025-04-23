#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int maxlength = 0; // max length
int sp = -1;       // starting point
// For memoization 
int t[1001][1001];
//Recursion call for check it is palindrome or not?
bool solve(string& s, int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    else if (s[i] == s[j])
    {
        return t[i][j] = solve(s, i+1, j-1);
    }else {
        return t[i][j] = false;
    }
}


string longestPalindrome(string s)
{
    int n = s.length();
    memset(t, -1, sizeof(t));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (solve(s, i, j) == true)
            {
                if (j - i + 1 > maxlength)
                {
                    maxlength = j - i + 1;
                    sp = i;
                }
            }
        }
    }

    return s.substr(sp, maxlength);
}

int main()
{
    cout << "5: Longest Palindrome Substring" << endl;
    string st = "babad";

    string result = longestPalindrome(st);
    cout << result << endl;
    return 0;
}