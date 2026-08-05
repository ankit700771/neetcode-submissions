class Solution {
public:

    set<vector<int>> ans;
    int n;

    void solve(vector<int>& nums, int i, vector<int>& curr) {

        if (i >= n) {
            ans.insert(curr);
            return;
        }

        // Take
        curr.push_back(nums[i]);
        solve(nums, i + 1, curr);

        // Don't take
        curr.pop_back();
        solve(nums, i + 1, curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        n = nums.size();
        vector<vector<int>> result;
        solve(nums, 0, curr);

        for(auto s: ans) {
            result.push_back(s);
        }

        return result;
    }
};
