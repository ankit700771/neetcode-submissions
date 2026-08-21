class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
        visited[u] = true;

        for(auto &v: adj[u]) {
            if(!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;

        for(vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i< n; i++) {
            if(!visited[i]) {
                DFS(adj, i, visited);
                count++;
            }
        }

        return count;

    }
};
