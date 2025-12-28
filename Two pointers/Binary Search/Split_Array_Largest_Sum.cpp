#include<iostream>
#include<vector>
using namespace std;

// Brute Force Recursive Solution
class Solution {
    public: int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        return dfs(nums, 0, k, n);
    }
    private: int dfs(vector<int>& nums, int i, int m, int n) {
        if (i == n) {
            return m == 0 ? 0 : INT_MAX;
        }

        if (m == 0) {
            return INT_MAX;
        }

        int res = INT_MAX, currSum = 0;
        for (int j = i; j <= n - m; j++) {
            currSum += nums[j];
            res = min(res, max(currSum, dfs(nums, j + 1, m - 1, n)));
        }

        return res;
    }
};

// Optimized Binary Search Solution
class Solution {
private: 
    bool canSplit(vector<int>& nums, int k, int largest){
        int subarray = 1, currSum = 0;
        for(int num: nums){
            currSum += num;
            if(currSum > largest){
                subarray++;
                if(subarray > k) return false;
                currSum = num;
            }
        }

        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        int res = r;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canSplit(nums, k, mid)){
                res = mid; 
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    cout << "Split Array Largest Sum" << endl;
    Solution solution;
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    int result = solution.splitArray(nums, k);
    cout << "Result: " << result << endl;
    return 0;
}