#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Brute Force Approach with O(n^2) time complexity and O(1) space complexity
// This problem is tricky from where when we take width of rightMost and leftMost
// values we need to take care of the condition and Final calculation of maximum area

/* class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int height = heights[i];

            int rightMostVal = i+1;
            while(rightMostVal < n && heights[rightMostVal] >= height){
                rightMostVal++;
            }

            int leftMostVal = i;
            while(leftMostVal >= 0 && heights[leftMostVal] >= height){
                leftMostVal--;
            }

            rightMostVal--;
            leftMostVal++;
            maxArea = max(maxArea, height * (rightMostVal - leftMostVal + 1));
        }

        return maxArea;
    }
};
*/

// Optimized Approach using Stack with O(n) time complexity and O(n) space complexity
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n , 0);
        vector<int> right(n , 0);
        stack<int> st;

        // Right smaller 
        for(int i = n - 1; i >= 0; i--){
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // we clean the stack 
        while(!st.empty()){
            st.pop();
        }

        // Left smaller
        for(int i = 0; i < n; i++){
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans = 0;
        // Now we calculate the currArea
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }

        return ans;
    }
};

int main() {
    cout << "Largest Rectangle In Histogram" << endl;
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << result << endl;
    return 0;
}