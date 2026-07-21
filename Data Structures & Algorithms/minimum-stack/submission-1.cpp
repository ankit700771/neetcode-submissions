class MinStack {
public:
    vector<int>stack;
    vector<int> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if(min_stack.size() == 0) {
            min_stack.push_back(val);
            return;
        } else {
            int minimum = min(min_stack[min_stack.size() - 1], val);
            min_stack.push_back(minimum);
        }
    }
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return min_stack[min_stack.size() - 1];
    }
};
