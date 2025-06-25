class Solution {
public:
    string generate(string& s) {
        int arr[26] = {0};

        for(char &ch: s){
            arr[ch - 'a']++; // increase the frequency
        }

        string n_word;

        for(int i = 0; i < 26; i++){
            if(arr[i] > 0){
                n_word += string(arr[i], i + 'a'); // we note the string with freq
            }
        }

        return n_word;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < n; i++) {
            string word = strs[i];

            string new_word = generate(word);

            map[new_word].push_back(word);
        }

        vector<vector<string>> result;
        for(auto& it: map){
            result.push_back(it.second);
        }

        return result;
    }
};