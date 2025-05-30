#include<iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
    public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};

        for (int c : s)
        {
            if (mapping.find(c) == mapping.end())
            {
                st.push(c);
            }
            else if (!st.empty() && mapping[c] == st.top())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }

        return st.empty() ? true : false;
    }
};


int main() {
    cout << "Valid Parentheses" << endl;
    string s = "()";
    Solution sol;
    bool result = sol.isValid(s);

    cout << result << endl;
    return 0;
}