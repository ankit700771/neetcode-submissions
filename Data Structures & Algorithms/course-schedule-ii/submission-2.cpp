class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegre(n, 0);
        for(auto &pre: prerequisites) {
            int v = pre[0];
            int u = pre[1];

            adj[u].push_back(v);
            indegre[v]++;
        }

        queue<int> q;
        vector<int> result;
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(indegre[i] == 0) {
                q.push(i);
                result.push_back(i);
                count++;
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v: adj[u]) {
                indegre[v]--;
                if(indegre[v] == 0) {
                    count++;
                    result.push_back(v);
                    q.push(v);
                }
            }
        }

        if(count == n)
            return result;
        return {};
        
    }
};
