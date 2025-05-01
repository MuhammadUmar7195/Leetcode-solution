#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int n = s.size();
        string answer = "";
        for (int i = 0; i < n; i++)
        {
            string prepareWord = "";
            while(i < n && s[i] == ' ') i++;
            while (i < n && s[i] != ' ')
            {
                prepareWord += s[i];
                i++;
            }
            reverse(prepareWord.begin(), prepareWord.end());
            if (prepareWord.length() > 0)
            {
                answer += ' ' + prepareWord;
            }
        }

        return answer.substr(1);
    }
};
int main()
{
    cout << "Reverse word in the string" << endl;
    Solution sol;
    string s = "blue is the sky";

    string result = sol.reverseWords(s);
    cout << result << endl;
    return 0;
}