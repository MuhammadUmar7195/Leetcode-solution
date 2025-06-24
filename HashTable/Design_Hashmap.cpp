#include <iostream>
#include <vector>
using namespace std;

class MyHashMap
{
public:
    vector<int> hashmap;
    MyHashMap() : hashmap(1000001, -1) {}

    void put(int key, int value) { hashmap[key] = value; }

    int get(int key) { return hashmap[key]; }

    void remove(int key) { hashmap[key] = -1; }
};

int main()
{
    cout << "Design Hashmap" << endl;
    MyHashMap map;

    map.put(1, 1);
    cout << map.get(1) << endl;
    map.remove(1);
    cout << map.get(1) << endl; 

    return 0;
}
