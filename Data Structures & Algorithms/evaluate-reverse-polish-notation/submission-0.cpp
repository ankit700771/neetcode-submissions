class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        for(int i = 0; i<n; i++) {
            if(tokens[i] == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first + second);
            } else if(tokens[i] == "*") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first * second);
            } else if(tokens[i] == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second / first);
            } else if(tokens[i] == "-") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second - first);
            } else {
                st.push(stoi(tokens[i]));
            }

        }
        return st.top();
    }
};
