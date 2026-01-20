// Design Circular Queue
// Brute Force Approach using Vector
// Time Complexity: O(1) for enQueue, Front, Rear, isEmpty, isFull
// O(n) for deQueue due to erase at the beginning of vector
// Space Complexity: O(k) where k is the capacity of the queue

class MyCircularQueue {
public:
    vector<int> q;
    int capacity;
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(q.size() == capacity){
            return false;
        }
        q.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(q.empty()){
            return false;
        }
        q.erase(q.begin());
        return true;
    }
    
    int Front() {
        return q.empty() ? -1 : q.front();
    }
    
    int Rear() {
        return q.empty() ? -1 : q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size() == capacity;
    }
};


// Optimized Approach using Circular Array
// Time Complexity: O(1) for all operations
// Space Complexity: O(k) where k is the capacity of the queue

class MyCircularQueue {
public:
    vector<int> q;
    int front;
    int rear;
    int size;
    int capacity;

    MyCircularQueue(int k) {
        q = vector<int>(k);
        front = 0; 
        size = 0;
        rear = -1;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % capacity;
        q[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
