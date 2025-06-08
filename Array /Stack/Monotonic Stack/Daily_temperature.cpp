#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }

        return ans;
    }
};


int main()
{
    cout << "Daily Temperatures" << endl;
    Solution sol;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    cout << "Result: ";
    for (int temp : result)
    {
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}