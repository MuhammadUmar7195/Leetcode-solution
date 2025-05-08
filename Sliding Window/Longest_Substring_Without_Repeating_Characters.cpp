#include<iostream>
#include <unordered_set>
using namespace std;


class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> seenMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++)
        {
            while (seenMap.find(s[right]) != seenMap.end())
            {
                seenMap.erase(s[left++]);
            }
            seenMap.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};


int main() {
    cout << "Longest Substring Without Repeating Characters" << endl;
    Solution sol;

    string s = "abcabcbb";
    int result = sol.lengthOfLongestSubstring(s);

    cout << result << endl;
    return 0;
}