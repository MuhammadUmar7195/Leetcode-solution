#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ----------------------------------------------Approach(Brute Force)----------------------------------------------------------------

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         //O(n^3) TC
//         for (int i = 0; i < nums.size(); i++) { // n*n*n
//             for (int j = i + 1; j < nums.size(); j++) {
//                 for (int k = j + 1; k < nums.size(); k++) {
//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         result.push_back({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }

//         return result;
//     }
// };

// ----------------------------------------------Approach(optimized way)----------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++)
        {
            //skip duplicate indexes
            if (i > 0 && nums[i] == nums[i-1]) continue; // continue means "i" ki value barha do 
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};

int main()
{
    cout << "3 Sum problem" << endl;

    vector<int> testcase1 = {-1, 0, 1, 2, -1, -4};

    Solution sol;
    vector<vector<int>> result = sol.threeSum(testcase1);

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