#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while (j < n)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
            j++;
        }

        return i + 1;
    }
};

int main()
{
    cout << "Remove Duplicates from Sorted Array" << endl;
    Solution sol;
    vector<int> testcase1 = {1, 1, 2};
    int result = sol.removeDuplicates(testcase1);
    cout << result << endl;
    return 0;
}