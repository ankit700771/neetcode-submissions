class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int>ans;
        int n = nums.size();
        unordered_map<int, int>umap;
        vector<int> ans1;
        for(auto x: nums) {
            umap[x]++;
            if(umap[x] > int(n/3)) {
                ans.insert(x);
            }
        }

        for(auto x: ans) {
            ans1.push_back(x);
        }

        return ans1;
    }
};