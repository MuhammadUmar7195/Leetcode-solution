#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; ++right)
        {
            sum += nums[right];

            while (sum >= target)
            {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};

int main()
{
    cout << "Minimum Size Subarray Sum" << endl;
    Solution sol;

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int k = 7;
    int result = sol.minSubArrayLen(k, nums);

    cout << result << endl;

    return 0;
}