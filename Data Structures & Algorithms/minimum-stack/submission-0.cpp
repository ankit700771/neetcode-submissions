class MinStack {
public:
    vector<int>stack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        int minElement = INT_MAX;
        for(int i = 0; i<stack.size(); i++) {
            minElement = min(minElement, stack[i]);
        }
        return minElement;
    }
};
