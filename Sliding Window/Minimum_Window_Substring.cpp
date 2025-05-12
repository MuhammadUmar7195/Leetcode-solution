#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {

        if (s.length() < t.length())
        {
            return "";
        }

        int requiredCount = t.length();
        unordered_map<char, int> map;
        int start = 0, end = 0;
        int minWindowSize = INT_MAX; // suppose infinity
        int minStart = 0;

        // Count the frequency of t
        for (char &ch : t)
        {
            map[ch]++;
        }
        // story begins
        while (end < s.length())
        {                           // jab tak end pointer last taak nhi chal jata
            char char_END = s[end]; // note end value
            if (map[char_END] > 0)
            {
                requiredCount--;
            }
            map[char_END]--;
            // shrink the window
            while (requiredCount == 0)
            {
                if (minWindowSize > end - start + 1)
                {
                    minWindowSize = end - start + 1;
                    minStart = start;
                }

                char char_START = s[start];
                map[char_START]++;
                if (map[char_START] > 0)
                {
                    requiredCount++;
                }
                start++;
            }
            end++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(minStart, minWindowSize);
    }
};

int main()
{
    cout << "Minimum Window Substring" << endl;

    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;

    string result = sol.minWindow(s, t);

    cout << result << endl;
    return 0;
}