#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> st;
        int n = s.length();
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            lastIndex[ch - 'a'] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            if (taken[idx] == true)
                continue;
            while (!st.empty() && s[i] < st.top() && lastIndex[st.top() - 'a'] > i)
            {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            taken[idx] = true;
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
    cout << "Remove Duplicate Letters: " << endl;
    string s = "bcabc";
    Solution sol;
    string result1 = sol.removeDuplicateLetters(s);
    cout << result1;

   return 0;
}