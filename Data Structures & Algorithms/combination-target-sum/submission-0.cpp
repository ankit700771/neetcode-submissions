class Solution {
public:

    void solve(vector<int>& nums, int target, int i, vector<vector<int>>&ans, vector<int>&res) {

        if(target < 0 || i >= nums.size()) {
            return;
        }

        if(target == 0) {
            ans.push_back(res);
            return;
        }

        res.push_back(nums[i]);
        solve(nums, target-nums[i], i, ans, res);
        res.pop_back();
        solve(nums, target, i+1, ans, res);
        return;

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;

        solve(nums, target, 0, ans, res);
        return ans;
    }
};
