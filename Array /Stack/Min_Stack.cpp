#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }else {
            int minVal = min(val, st.top().second);
            st.push({val, minVal});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    cout << "Min Stack" << endl;
    MinStack st;
    st.push(3);
    st.push(1);
    st.push(0);
    st.pop();
    st.top();
    int result = st.getMin();
    cout << result << endl;
    return 0;
}