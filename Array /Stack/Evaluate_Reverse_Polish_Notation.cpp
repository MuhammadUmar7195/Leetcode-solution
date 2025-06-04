#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int Operate(int &a, int &b, const string &s)
    {
        switch (s[0])
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
        }
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int result = 0;
        for (string &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                result = Operate(b, a, token);
                st.push(result);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

int main()
{
    cout << "Evaluate Reverse Polish Notation" << endl;
    Solution sol;

    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = sol.evalRPN(tokens);

    cout << result << endl;
    return 0;
}