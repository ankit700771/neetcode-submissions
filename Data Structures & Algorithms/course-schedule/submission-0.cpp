class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &pre: prerequisites) {
            int v = pre[0];
            int u = pre[1];
            adj[u].push_back(v);
        }

        vector<int> indegre(n, 0);
        queue<int> q;
        int count = 0;

        for(int u = 0; u<n; u++) {
            for(auto &v: adj[u]) {
                indegre[v]++;
            }
        }

        for(int i = 0; i<n; i++) {
            if(indegre[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto &v: adj[u]) {
                indegre[v]--;
                if(indegre[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        if(count == n) {
            return true;
        }
        return false;
    }
};
