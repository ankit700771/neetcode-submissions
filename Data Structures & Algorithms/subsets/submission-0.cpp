class Solution {
public:
    set<vector<int>> st;

    void solve(vector<int> &nums, int i, vector<int>& res, int &n) {
        if(i >= n) {
            st.insert(res);
            return;
        }

        res.push_back(nums[i]);
        solve(nums, i+1, res, n);
        res.pop_back();
        solve(nums, i+1, res, n);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> res;

        solve(nums, 0, res, n);

        for(auto s: st) {
            ans.push_back(s);
        }

        return ans;
    }
};
