class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int i = n-1;
        stack<pair<int, int>>st;
        vector<int>ans(n , 0);

        while(i >= 0) {
            while(!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }

            if(!st.empty() && st.top().first > temperatures[i]) {
                ans[i] = st.top().second - i;
                st.push({temperatures[i], i});
                i--;
            }

            if(st.empty()) {
                st.push({temperatures[i], i});
                i--;
            }
        }

        return ans;
    }
};
