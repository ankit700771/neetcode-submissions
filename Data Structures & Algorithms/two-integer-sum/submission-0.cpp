class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>lookup;
        for(int i = 0; i<nums.size(); i++) {
            if(lookup.find(target-nums[i]) != lookup.end()) {
                return {lookup[target-nums[i]], i};
            }

            lookup[nums[i]] = i;
            
        }
        return {};
    }
};
