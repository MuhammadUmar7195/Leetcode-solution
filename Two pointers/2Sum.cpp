#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ----------------------Approach(Binary search/Two pointer)-----------------------------------------
// TC O(logn)
// SC O(n) which is Memory limit exceed
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> pairIndexValue;

        for (int i = 0; i < n; i++)
        {
            pairIndexValue.push_back({nums[i], i});
        }
        sort(pairIndexValue.begin(), pairIndexValue.end());

        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int sum = pairIndexValue[left].first + pairIndexValue[right].first;
            if (sum == target)
            {
                return {pairIndexValue[left].second, pairIndexValue[right].second};
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
        return {};
    }
};

int main()
{
    cout << "Hello, World!" << endl;

    vector<int> testcase1 = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(testcase1, target);

    for (auto &num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}