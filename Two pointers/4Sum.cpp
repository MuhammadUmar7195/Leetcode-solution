#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ----------------------------------------------Approach(optimized way----------------------------------------------------------------
// TC (nlogn + n^3) => O(n^3)
// SC O(logn)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n; i++)
        {
            // skip the further part when you see duplicate of next i index
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                // skip the further part when you see duplicate of next j index
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = n - 1;

                while (left < right)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[left] +
                                    (long long)nums[right];

                    if (sum == target)
                    {
                        result.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        // skip duplicates for left and right
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    cout << "3 Sum problem" << endl;

    vector<int> testcase1 = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;
    // vector<int> testcase1 = {2, 2, 2, 2, 2};
    // int target = 8;
    // vector<int> testcase1 = {1, 0, -1, 0, -2, 2};
    // int target = 0;
    Solution sol;
    vector<vector<int>> result = sol.fourSum(testcase1, target);

    for (const auto &triplet : result)
    {
        cout << "[";
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}