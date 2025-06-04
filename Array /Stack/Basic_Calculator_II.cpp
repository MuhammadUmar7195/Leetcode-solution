#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int num = 0;
        char op = '+';
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int tmp = st.top(); st.pop();
                    st.push(tmp * num);
                } else if (op == '/') {
                    int tmp = st.top(); st.pop();
                    st.push(tmp / num);
                }
                op = s[i];
                num = 0;
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};