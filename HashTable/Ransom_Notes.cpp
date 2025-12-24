class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

        for(auto c: magazine){
            map[c]++; // increase and note the frequency of each character.
        }

        //Then we have to note in ransomNote
        for(auto c: ransomNote){
            if(map[c] <= 0)
                return false;
            map[c]--;
        }

        return true;
    }
};