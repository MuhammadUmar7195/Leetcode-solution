#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //O(n^3) TC
        for (int i = 0; i < nums.size(); i++) { // n*n*n
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    cout << "3 Sum problem" << endl;

    vector<int> testcase1 = {-1, 0, 1, 2, -1, -4};

    Solution sol;
    vector<vector<int>> result = sol.threeSum(testcase1); 


    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}