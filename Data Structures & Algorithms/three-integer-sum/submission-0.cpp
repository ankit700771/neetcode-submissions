class Solution {
public:

    void helperFunction(vector<int>& nums, int start, int end, int target, vector<vector<int>>&ans ) {
        while(start < end) {
            if(nums[start] + nums[end] > target) end--;
            else if(nums[start] + nums[end] < target) start++;
            else {
                while(start < end && nums[start] == nums[start+1]) start++;
                while(start < end && nums[end] == nums[end-1]) end--;
                ans.push_back({-target, nums[start], nums[end]});
                start++;
                end--;
            }

        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i-1])
            helperFunction(nums, i+1, nums.size()-1, -nums[i], ans);
        }

        return ans;



    }
};
