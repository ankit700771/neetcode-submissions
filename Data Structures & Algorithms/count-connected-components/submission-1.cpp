class Solution {
public:
    void BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
        queue<int> q;

        q.push(u);
        visited[u] = true;

        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            for(auto &v: adj[temp]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
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
                BFS(adj, i, visited);
                count++;
            }
        }

        return count;

    }
};
