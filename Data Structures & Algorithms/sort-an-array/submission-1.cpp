class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        // implement using counting sort
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        vector<int> res;
        unordered_map<int,int>umap;
        for(auto x: nums) {
            umap[x]++;
        }

        for(int i = min; i<=max; i++) {
            if(umap.find(i) != umap.end()) {
                int count = umap[i];
                while(count > 0) {
                    res.push_back(i);
                    count--;
                }
            }
        }

        return res;
    }
};