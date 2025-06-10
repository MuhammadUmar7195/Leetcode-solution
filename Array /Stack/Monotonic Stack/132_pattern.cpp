#include <stack>
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int num3 = INT_MIN;
        stack<int>st;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < num3) {
                return true;
            }

            while (!st.empty() && st.top() < nums[i]) {
                num3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;

    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    bool result = solution.find132pattern(nums);
    // Output: false
    cout << (result ? "true" : "false") << endl;
    return 0;
}
