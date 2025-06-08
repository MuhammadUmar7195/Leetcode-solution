#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> st;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            int result = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
            umap.insert({nums2[i], result});
        }
        vector<int> ans;

        for (auto x : nums1) {
            ans.push_back(umap[x]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// The time complexity is O(n + m) where n is the size of nums1 and m is the size of nums2.
// The space complexity is O(m) for the unordered_map and stack.
