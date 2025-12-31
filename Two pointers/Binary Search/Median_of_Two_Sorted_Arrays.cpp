#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>
using namespace std;


// brute force approach with O((m+n)log(m+n)) time complexity SC O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = nums1;
           merged.insert(merged.end(), nums2.begin(), nums2.end());

        sort(merged.begin(), merged.end());
        int n = merged.size();

        if(n % 2 == 0){
            //for even we deal float nums
            return (merged[n/2 - 1] +merged[n/2]) / 2.0;
        }else {
            // for odd num
            return merged[n/2];
        }
        
    }
};

//Optimal approach with O(log(min(m,n))) time complexity SC O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;  // +1 to handle both odd and even cases
        
        int left = 0, right = m;
        
        while (left <= right) {
            // Partition nums1: we take i elements from nums1
            int i = left + (right - left) / 2;
            
            // Partition nums2: we take j elements from nums2
            // i + j = half (or half+1 for odd case)
            int j = half - i;
            
            // Get the four boundary elements
            int nums1Left = (i > 0) ? nums1[i - 1] : INT_MIN;
            int nums1Right = (i < m) ? nums1[i] : INT_MAX;
            int nums2Left = (j > 0) ? nums2[j - 1] : INT_MIN;
            int nums2Right = (j < n) ? nums2[j] : INT_MAX;
            
            // Check if partition is correct
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                // Found correct partition
                if (total % 2 == 0) {
                    // Even total length: average of max(left) and min(right)
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                } else {
                    // Odd total length: max of left partition
                    return max(nums1Left, nums2Left);
                }
            }
            else if (nums1Left > nums2Right) {
                // Too many elements from nums1, move left
                right = i - 1;
            }
            else {
                // Too few elements from nums1, move right
                left = i + 1;
            }
        }
        
        return 0.0;  // Should never reach here if inputs are valid
    }
};

int main() {
    cout << "Median of Two Sorted Arrays" << endl;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl; 
    return 0;
}