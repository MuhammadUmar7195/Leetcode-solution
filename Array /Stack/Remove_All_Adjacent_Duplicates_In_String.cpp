#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (!st.empty() && st.top() == c)
            {
                st.pop();
            }
            else
            {
                st.push(c);
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
    cout << "Remove All Adjacent Duplicates In String" << endl;
    string s = "abbaca";
    Solution sol;
    string result  = sol.removeDuplicates(s);
    
    for (char res : result){
        cout << res;
    }
    cout << endl;
    return 0;
}