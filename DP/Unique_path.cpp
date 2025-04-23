#include <iostream>
using namespace std;

int solve(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    if ((i < 0 || i >= m) || (j < 0 || j >= n))
    { // out of bound
        return 0;
    }

    int right = solve(i, j + 1, m, n);
    int down = solve(i + 1, j, m, n);

    return right + down;
}

int uniquePath(int m, int n)
{
    return solve(0, 0, m, n);
}

int main()
{
    cout << "Unique Path" << endl;
    int m = 3;
    int n = 7;

    cout << uniquePath(m, n) << "\n";

    return 0;
}