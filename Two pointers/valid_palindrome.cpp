#include <iostream>
#include <cctype>
using namespace std;


class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.length() - 1;

        while (start < end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }

        return true;
    }
};

int main()
{
    cout << "Valid Palindrome" << endl;
    Solution sol;
    string s = "race a car";

    bool result  = sol.isPalindrome(s);
    cout << result << endl;

    return 0;
}