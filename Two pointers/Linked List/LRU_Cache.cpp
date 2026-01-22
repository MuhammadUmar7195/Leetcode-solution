// (Brute Force) => LRU Cache implementation using vector and pair
// Time Complexity: O(n) for get and put operations
// Space Complexity: O(capacity) for storing the cache
class LRUCache {
    vector<pair<int, int>> cache;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                pair<int, int> tmp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        if(cache.size() == capacity){
            cache.erase(cache.begin());
        }

        cache.push_back({key, value});
    }
};

// (Optimal) => LRU Cache implementation using doubly linked list and hashmap
// Time Complexity: O(1) for get and put operations
// Space Complexity: O(capacity) for storing the cache
class LRUCache {
public:
    list<int> dll; //it contains the key
    map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;
        }
        
        if(capacity < 0) {
            cache.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};