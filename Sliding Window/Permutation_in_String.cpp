#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();

        if (len1 > len2)
            return false;

        vector<int> s1Hash(26, 0);
        vector<int> s2Hash(26, 0);

        // Initialize the frequency count for s1 and the first window of s2
        for (int i = 0; i < len1; i++)
        {
            s1Hash[s1[i] - 'a']++;
            s2Hash[s2[i] - 'a']++;
        }

        if (s1Hash == s2Hash)
            return true;

        // Sliding window over the rest of s2
        for (int i = len1; i < len2; i++)
        {
            s2Hash[s2[i] - 'a']++;
            s2Hash[s2[i - len1] - 'a']--;

            if (s1Hash == s2Hash)
                return true;
        }

        return false;
    }
};

int main()
{
    cout << "Permutation in String" << endl;
    Solution sol;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool result = sol.checkInclusion(s1, s2);
    cout << result << endl;
    return 0;
}