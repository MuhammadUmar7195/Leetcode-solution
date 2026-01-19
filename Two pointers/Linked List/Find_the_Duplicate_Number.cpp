
// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/
// Time Complexity: O(n log n) due to sorting and space complexity: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }

        return -1;
        
    }
};

// we can use hashsets to solve this problem in O(n) time and O(n) space complexity
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num : nums){
            if(seen.find(num) != seen.end()){
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};
