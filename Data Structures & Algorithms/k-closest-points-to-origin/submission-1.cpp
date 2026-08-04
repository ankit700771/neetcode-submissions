class Solution {
public:
    priority_queue<
        pair<double, pair<int, int>>,
        vector<pair<double, pair<int, int>>>,
        greater<pair<double, pair<int, int>>>
    > pq;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;

        for(int i = 0; i< points.size(); i++) {
            double distance = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);

            pq.push({
                distance,
                {points[i][0], points[i][1]}
            });
        }

        while(k--) {
            ans.push_back({
                pq.top().second.first,
                pq.top().second.second
            });
            pq.pop();
        }

        return ans;
    }
};
