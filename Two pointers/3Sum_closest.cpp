#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
// ----------------------------------------------Approach(optimized way)----------------------------------------------------------------
// O() TC
// O() SC
class Solution
{
public:
    int minDifference = INT_MAX;

    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int resultSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    return sum;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }

                int diffToTarget = abs(sum - target);
                if (diffToTarget < minDifference)
                {
                    resultSum = sum;
                    minDifference = diffToTarget;
                }
            }
        }
        return resultSum;
    }
};

int main()
{
    cout << "3 Sum closest" << endl;

    vector<int> testcase1 = {-1, 2, 1, -4};
    int target = 1;
    Solution sol;
    int result = sol.threeSumClosest(testcase1, target);
    cout << result << endl;
    return 0;
}