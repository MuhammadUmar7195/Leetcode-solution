#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach O(n) and O(1) space
class Solution {
public:
    int findMin(vector<int> &nums) {
        return *min_element(nums.begin(), nums.end());
    }
};

// Optimal Approach O(log n) and O(1) space
class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0; 
        int r = nums.size() - 1;
        int res = nums[0];

        while(l <= r){
            if(nums[l] < nums[r]){
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);

            if(nums[mid] <= nums[l]){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    cout << "Find Minimum in Rotated Sorted Array" << endl;
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Minimum element is: " << sol.findMin(nums) << endl;
    return 0;
}