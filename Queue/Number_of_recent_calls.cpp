/**
* Your RecentCounter object will be instantiated and called as such:
* RecentCounter* obj = new RecentCounter();
* int param_1 = obj->ping(t);
**/


// By using Queue 
class RecentCounter {
public:
    queue<int> q;
    int i;
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (!q.empty() && t - q.front() > 3000) {
            q.pop();
        }
        return q.size();
    }
};

// Using pointers (sliding window)
class RecentCounter {
public:
    vector<int> listOfRecord;
    int i;
    RecentCounter() { i = 0; }

    int ping(int t) {
        listOfRecord.push_back(t);
        while (i < listOfRecord.size() && listOfRecord[i] < t - 3000) {
            i++;
        }
        return listOfRecord.size() - i;
    }
};
