#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        long long currentSum = 0, maxSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            currentSum += nums[i];
            freq[nums[i]]++;

            if (i >= k)
            {
                currentSum -= nums[i - k];
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0)
                {
                    freq.erase(nums[i - k]);
                }
            }

            if (i >= k - 1 && freq.size() == k)
            {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};

int main()
{
    cout << "Maximum Sum of Distinct Subarrays with length K" << endl;

    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;

    Solution sol;
    long long result = sol.maximumSubarraySum(nums, k);

    cout << result << endl;
    return 0;
}