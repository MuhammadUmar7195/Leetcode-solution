#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        int windowSize = 0;

        for (int i = 0; i < k; i++)
        {
            windowSize += nums[i];
        }

        int maxSum = windowSize;

        // Slide the window k
        for (int i = k; i < n; i++)
        {
            windowSize += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSize);
        }

        // When you run this code the output is 12.00000 but if you double data
        // type then answer will expected 12.7500
        return (double)maxSum / k;
    }
};

int main()
{
    cout << "Maximum average subarray" << endl;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    Solution sol;
    double result = sol.findMaxAverage(nums, k);
    cout << result << endl;
    return 0;
}