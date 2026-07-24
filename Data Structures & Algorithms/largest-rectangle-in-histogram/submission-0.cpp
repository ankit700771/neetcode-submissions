class Solution {
public:

    vector<int> next_small_element(vector<int> &arr) {
        int n = arr.size();
        vector<int>ans(n, 0);
        stack<pair<int, int>>st;
        int i = n-1;
        while(i >= 0) {
            
            if(st.empty()) {
                st.push({INT_MIN, n});
            }
            
            while(st.top().first >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top().second;
            st.push({arr[i], i});
            i--;
        }
        
        return ans;
    }

    vector<int> prev_small_element(vector<int> &arr) {
        int n = arr.size();
        vector<int>ans(n, 0);
        stack<pair<int, int>>st;
        int i = 0;
        while(i < n) {
            if(st.empty()) {
                st.push({INT_MIN, -1});
            }
            
            while(st.top().first >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top().second;
            st.push({arr[i], i});
            i++;
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>NSE = next_small_element(heights);
        vector<int>PSE = prev_small_element(heights);
        int maxArea = INT_MIN;

        for(int i = 0; i<heights.size(); i++) {
            maxArea = max(maxArea, (heights[i] * (NSE[i] - PSE[i] - 1)));
        }

        return maxArea;
        
    }
};
