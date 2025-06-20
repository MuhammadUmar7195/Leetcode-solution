
/*Approach 1
We use simulation where we sort the array first. Declare two pointers, bool skip for better iteration
in result array. Put the index value in result then skip is true. If j index is on end we circulate the
index and put remaining values in result.
Time => O(nlogn)
Space => O(1)
*/

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        vector<int> result(n, 0);
        int i, j = 0;
        bool skip = false;

        sort(begin(deck), end(deck));

        for (i = 0; i < n;)
        {
            if (result[j] == 0)
            {
                if (skip == false)
                {
                    result[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            j = (j + 1) % n;
        }

        return result;
    }
};

/*Approach 2
We declare a queue where we insert index until the size of deck array is not end. We simply put the
value of deck of "i" respect to queue in result array. Pop the element, then next index of queue is 
also pop and push back of queue. This process goes on until the queue is not empty. return the result.  
Time => O(nlogn)
Space => O(n)
*/

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        queue<int> q;
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }
        sort(begin(deck), end(deck));

        for (int i = 0; i < n; i++)
        {
            int index = q.front();
            q.pop();

            result[index] = deck[i];

            if (!q.empty())
            {
                int val = q.front;
                q.push(val);
                q.pop();
            }
        }

        return result;
    }
};
