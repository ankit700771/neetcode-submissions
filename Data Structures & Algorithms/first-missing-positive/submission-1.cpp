class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool>seen(nums.size()+1, false);

        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] > 0 && nums[i] <= nums.size()) {
                seen[nums[i]] = true;
            }
        }

        for(int i = 1; i<seen.size(); i++) {
            if(seen[i] == false) {
                return i;
            }
        }
    }
};