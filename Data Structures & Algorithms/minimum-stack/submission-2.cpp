class MinStack {
public:
    stack<pair<int, int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
            return;
        }
        pair<int, int> top = st.top();
        st.push({val, min(top.second, val)});
        return;
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
