#include <iostream>
#include <vector>
using namespace std;

/* INTITUTION
We need to observer and all concern is about time incrementation and return under k != 0
If each index is less than k value then we obtain the minimum of value or add in time varaiable. Unless i is
not greater than k value.
If we see the i is very big and k is small then we decrement the ticket k value and store in time. After all
value of i is big but concern is all about k value. When It is small then we return back k value itself. That's it.
*/

// Time => O(N)
// Space => O(1)
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int time = 0;

        for (int i = 0; i < n; i++)
        {
            if (i <= k)
            {
                time += min(tickets[k], tickets[i]);
            }
            else
            {
                time += min(tickets[k] - 1, tickets[i]);
            }
        }

        return time;
    }
};

/*
Using Queue, we need to first push each value of array in queue data structure
One by One we come out front value, increment time, pop the front element, decrement the front ticket value
If k value is match with front or value maybe 0 then return time. On the other hand, we push again this
ticket front value in queue data structure.
*/

// Time => O(N* M) => Loop runs until queue is empty and in worst case all people have maximum m tickets
// Space => O(1)
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int time = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }

        while (!q.empty())
        {
            time++;
            int front = q.front();
            q.pop();

            tickets[front]--;

            if (k == front && tickets[front] == 0)
            {
                return time;
            }

            if (tickets[front] != 0)
            {
                q.push(front);
            }
        }

        return time;
    }
};

int main()
{
    cout << "Time needed to buy tickets." << endl;

    Solution sol;

    vector<int> tickets = {7, 8, 3};
    int k = 2;

    int result = sol.timeRequiredToBuy(tickets, k);
    cout << result << endl;

    return 0;
}


// Both solution are correct.