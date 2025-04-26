#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int maxArea = 0;

        while(l<r){
            int minHeight = min(l, r);
            int width = r -l;
            maxArea = max(maxArea, width*minHeight);

            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea * maxArea;
    }
};

int main()
{
    cout << "Container with most water" << endl;

    Solution sol;
    vector<int> testcase1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = sol.maxArea(testcase1);

    cout << result << "\n" << endl;
    return 0;
}