class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& res,
               vector<vector<int>>& ans) {

        if (i == nums.size()) {
            ans.push_back(res);
            return;
        }

        // Take nums[i]
        res.push_back(nums[i]);
        solve(nums, i + 1, res, ans);

        // Don't take nums[i]
        res.pop_back();
        solve(nums, i + 1, res, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;

        solve(nums, 0, res, ans);

        return ans;
    }
};