#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach O(n) with O(1) space
class Solution
{
    public:
    int search(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }

        return -1;
    }
};


// Binary search Approach O(log n) with O(1) space
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[l] <= nums[mid])
            {
                if (target > nums[mid] || target < nums[l])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                if (target < nums[mid] || target > nums[r])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};


int main()
{
    cout << "Search in Rotated Sorted Array" << endl;
    Solution solution;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = solution.search(nums, target);
    cout << "Index of target " << target << " is: " << result << endl
    return 0;
}