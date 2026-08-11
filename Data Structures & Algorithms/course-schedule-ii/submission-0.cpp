class Solution {
public:

    bool DFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, stack<int> &st, int u, vector<bool> &inRecuresion) {
        visited[u] = true;
        inRecuresion[u] = true;
        for(int &v: adj[u]) {
            if(!visited[v] && DFS(adj, visited, st, v, inRecuresion)) {
               return true; 
            }

            if(inRecuresion[v]) {
                return true;
            }
        }
        inRecuresion[u] = false;
        st.push(u);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &pre: prerequisites) {
            int v = pre[0];
            int u = pre[1];

            adj[u].push_back(v);
        }

        stack<int> st;
        vector<bool>visited(n, false);
        vector<bool> inRecuresion(n, false);
        vector<int> result;

        for(int i = 0; i<n; i++) {
            if(!visited[i] && DFS(adj, visited, st, i, inRecuresion)) {
                return {};
            }
        }

        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
