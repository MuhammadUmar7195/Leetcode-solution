#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pHash(26, 0);
        vector<int> sHash(26, 0);
        vector<int> result;
        for (char c : p)
        {
            // we increment frequency with ascii of character
            pHash[c - 'a']++; 
        }

        // We increment frequency of string s
        for (int i = 0; i < p.size(); i++)
        {
            sHash[s[i] - 'a']++;
        }
        // Both freq match store 0 index in array
        if (pHash == sHash)
            result.push_back(0);

        // Slide the window
        for (int k = p.size(); k < s.size(); k++)
        {
            sHash[s[k] - 'a']++;
            sHash[s[k - p.size()] - 'a']--;

            if (sHash == pHash)
                result.push_back(k - p.size() + 1);
        }

        return result;
    }
};

int main()
{
    cout << "Find All Anagrams in a String" << endl;

    string s = "cbaebabacd";
    string p = "abc";
    Solution sol;

    vector<int> result = sol.findAnagrams(s, p);
    
    for (int i = 0; i < result.size(); i++){
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}