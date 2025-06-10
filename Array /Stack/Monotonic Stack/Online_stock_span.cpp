#include <iostream>
#include <stack>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner() {}

    int next(int price)
    {
        int span = 1;

        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};



int main()
{
    cout << "Online stock span" << endl;
    StockSpanner stockSpanner;  

    cout << stockSpanner.next(100) << endl; // returns 1
    cout << stockSpanner.next(80) << endl;  // returns 1
    cout << stockSpanner.next(60) << endl;  // returns 1
    cout << stockSpanner.next(70) << endl;  // returns 2    
    cout << stockSpanner.next(60) << endl;  // returns 1
    cout << stockSpanner.next(75) << endl;  // returns 4
    cout << stockSpanner.next(85) << endl;  // returns 6
    cout << stockSpanner.next(90) << endl;  // returns 7
    cout << stockSpanner.next(95) << endl;  // returns 8
    cout << stockSpanner.next(100) << endl; // returns 9
    cout << stockSpanner.next(105) << endl; // returns 10

    return 0;
}