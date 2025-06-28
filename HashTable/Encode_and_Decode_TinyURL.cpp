
/*
    Using map we store key value as num and store it with same longURl. 
    Create a integer and append it in made in string like tinyurl.com/1, then we store 1 as key with longUrl.
    On behave of key we return shortUrl in decode function with constant time.
    TC will be O(L) where L is the length of strings.
    SC O(n*l)
*/

class Solution {
public:
    map<string, string> map;
    int num = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ans = "http://tinyurl.com/";
        num++;
        string addOne = to_string(num);
        ans += (string)addOne;
        map[ans] = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return map[shortUrl]; }
};
