class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;

        for (char ch : text) {
            freq[ch]++;
        }

        int b = freq['b'];
        int a = freq['a'];
        int l = freq['l'] / 2;
        int o = freq['o'] / 2;
        int n = freq['n'];
        
        int minCountFreq = min({b, a, l, o, n});
        
        return minCountFreq;
    }
};