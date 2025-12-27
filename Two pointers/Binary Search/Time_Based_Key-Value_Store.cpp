#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach [O(n) for get and O(1) for set] with O(n) space
class TimeMap {
private: 
    unordered_map<string, vector<pair<int, string>>> keyVal;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyVal[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // 1. If key doesn't exist, return empty
        if (keyVal.find(key) == keyVal.end()) return "";

        const auto& history = keyVal[key];
        
        // 2. Search from the back of the vector to the front
        // This is "Easy" because the largest timestamp <= target is likely near the end
        for (int i = history.size() - 1; i >= 0; i--) {
            if (history[i].first <= timestamp) {
                return history[i].second;
            }
        }

        return "";
    }
};

// Binary Search Approach [O(log n) for get and O(1) for set] with O(n) space
class TimeMap {
private: 
    unordered_map<string, vector<pair<int, string>>> keyVal;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyVal[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // 1. If key doesn't exist, return empty
        if (keyVal.find(key) == keyVal.end()) return "";

        const auto& history = keyVal[key];
        int left = 0, right = history.size() - 1;
        string res = "";

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (history[mid].first <= timestamp) {
                res = history[mid].second; // potential answer
                left = mid + 1; // try to find a larger timestamp
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};

int main()
{
    cout << "Time Based Key-Value Store" << endl;
    TimeMap sol;
    sol.set("foo", "bar", 1);
    cout << sol.get("foo", 1) << endl; // return "bar"
    cout << sol.get("foo", 3) << endl; // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2
    sol.set("foo", "bar2", 4);
    cout << sol.get("foo", 4) << endl; // return "bar2"
    cout << sol.get("foo", 5) << endl; // return "bar2" 
    return 0;
}