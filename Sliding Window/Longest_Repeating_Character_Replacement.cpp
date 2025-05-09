#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int maxWindow = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++)
        {
            // Update the frequency
            freq[s[right]]++;
            // Get maximum frequency in map
            maxFreq = max(maxFreq, freq[s[right]]);

            int windowLength = right - left + 1;
            if (windowLength - maxFreq > k)
            {
                freq[s[left]]--;
                left++;
                windowLength = right - left + 1;
            }

            maxWindow = max(maxWindow, windowLength);
        }

        return maxWindow;
    }
};

int main()
{
    cout << "Maximum Sum of Distinct Subarrays with length K" << endl;

    string s = "ABAB";
    int k = 2;

    Solution sol;
    int result = sol.characterReplacement(s, k);

    cout << result << endl;
    return 0;
}