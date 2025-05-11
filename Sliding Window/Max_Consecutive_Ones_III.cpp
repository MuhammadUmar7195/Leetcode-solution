#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int window = 0;
        int maxLength = 0;

        for (int right = 0; right < n; right++)
        {
            window += nums[right];

            while ((right - left + 1) - window > k)
            {
                window -= nums[left];
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main()
{
    cout << "Max Consecutive Ones III" << endl;
    Solution sol;

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int result = sol.longestOnes(nums, k);
    cout << result << endl;
    return 0;
}