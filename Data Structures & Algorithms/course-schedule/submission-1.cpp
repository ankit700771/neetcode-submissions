class Solution {
public:

    bool DFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, vector<bool> &inRecuresion) {
        visited[u] = true;
        inRecuresion[u] = true;
        for(int &v: adj[u]) {

            if(!visited[v] && DFS(adj, visited, v, inRecuresion)) {
                return true;
            }

            if(inRecuresion[v]) {
                return true;
            }

        }
        inRecuresion[u] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &pre: prerequisites) {
            int v = pre[0];
            int u = pre[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);
        vector<bool> inRecuresion(n, false);

        for(int i =0; i<n; i++) {
            if(!visited[i] && DFS(adj, visited, i, inRecuresion)) {
                return false;
            }
        }

        return true;
    }
};
