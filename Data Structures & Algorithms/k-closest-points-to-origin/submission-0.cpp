class Solution {
public:
    priority_queue<
        pair<double, pair<int, int>>,
        vector<pair<double, pair<int, int>>>,
        greater<pair<double, pair<int, int>>>
    > pq;

    double calculateDistance(vector<int> point) {
        int x1 = 0;
        int y1 = 0;
        int x2 = point[0];
        int y2 = point[1];

        double distance = sqrt(
            pow(x2 - x1, 2) +
            pow(y2 - y1, 2)
        );

        return distance;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;

        for(int i = 0; i< points.size(); i++) {
            double distance = calculateDistance(points[i]);

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
