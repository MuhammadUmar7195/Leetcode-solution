#include<iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     //Brute Force Approach with O(n*max(piles)) time complexity
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int speed = 1;
//         while(true){
//             long totalTime = 0;
//             for(int pile : piles){
//                 totalTime += (pile + speed - 1) / speed;
//             }
//             if(totalTime <= h)
//                 return speed;
//             speed++;
//         }
//     }
// };

class Solution {
public:
    // Optimized Approach using Binary Search with O(n log(max(piles))) time complexity
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l <= r){
            int mid = l + (r - l) / 2; 

            long long totalTime = 0;
            for(int pile: piles){
                totalTime += ceil(static_cast<double>(pile) / mid);
            }

            if(totalTime <= h){
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << sol.minEatingSpeed(piles, h) << endl; // Output: 4
    return 0;
}