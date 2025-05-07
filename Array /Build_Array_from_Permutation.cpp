#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};

int main()
{
    cout << "Build Array from Permutation" << endl;
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    Solution sol;
    vector<int> result = sol.buildArray(nums);

    for (auto &num : result)
    {
        cout << num << "\n";
    }
    cout << endl;

    return 0;
}