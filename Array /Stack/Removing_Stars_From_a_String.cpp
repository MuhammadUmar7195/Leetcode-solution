#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        string result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    cout << "Removing Stars From a String" << endl;
    Solution sol; 
    string s = "leet**cod*e";
    string result = sol.removeStars(s);
    cout << result << endl;
    return 0;
}