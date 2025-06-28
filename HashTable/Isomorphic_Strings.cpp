#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.length(); i++) {
            char original = s[i];
            char replacement = t[i];

            if (mapST.count(original) && mapST[original] != replacement)
                return false;
            if (mapTS.count(replacement) && mapTS[replacement] != original)
                return false;
            mapST[original] = replacement;
            mapTS[replacement] = original;
        }

        return true;
    }
};