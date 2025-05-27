#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1)
            return 1.00;
        if (x == 0)
            return 0.00;
        long binForm = n;
        if (n < 0)
        {
            x = 1 / x; // reciprocal of x
            binForm = -binForm;
        }
        double ans = 1;

        while (binForm > 0)
        {
            if (binForm % 2 == 1)
            { // pick binary
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }

        return ans;
    }
};

int main()
{
    cout << "Pow (x, n) " << endl;
    Solution sol;

    double x = 3.000;
    int n = 2;

    double result = sol.myPow(x, n);

    cout << result << endl;
    return 0;
}