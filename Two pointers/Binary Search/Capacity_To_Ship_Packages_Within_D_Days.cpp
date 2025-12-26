#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
private: 
    bool canShip(const vector<int>& weights, int days, int cap){
        int ships = 1, currCap = cap;

        for(int w : weights){
            if(currCap - w < 0){
                ships++;
                if(ships > days){
                    return false;
                }
                currCap = cap;
            }
            currCap -= w;
        }

        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int res = r;

        while(l <= r){
            int midCapacity = l + (r - l) / 2;
            if(canShip(weights, days, midCapacity)){
                res = min(res, midCapacity);
                r = midCapacity - 1;
            }else {
                l = midCapacity + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << "Minimum capacity to ship packages within " << days << " days: " 
         << sol.shipWithinDays(weights, days) << endl;
    return 0;
}