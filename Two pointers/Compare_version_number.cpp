#include <iostream>
using namespace std;

int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    int n = version1.length(), m = version2.length();

    while (i < n || j < m)
    {
        int num1 = 0;
        while (i < n && version1[i] != '.')
        {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        int num2 = 0;
        while (j < m && version2[j] != '.')
        {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 > num2)
            return 1;
        if (num1 < num2)
            return -1;

        // skip dots
        i++;
        j++;
    }

    return 0;
}

int main()
{
    cout << "Compare version number" << endl;
    string s1 = "1.00";
    string s2 = "3.2";

    int result = compareVersion(s1, s2); 
    cout << result << endl;
    return 0;
}