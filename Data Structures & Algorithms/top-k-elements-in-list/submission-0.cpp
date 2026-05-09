class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        for(auto num: nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> res;
        for(auto x: count) {
            heap.push({x.second, x.first});
            if(heap.size() > k) {
                heap.pop();
            }
        }

        for(int i = 0; i< k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }

        return res;
    }
};
