class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = nums[0];
        int count = 1;

        for(int i = 1; i< nums.size(); i++) {
            if(nums[i] == value) {
                count++;
            }

            else if(nums[i] != value && count != 0) {
                count--;
            }

            else {
                value = nums[i];
                count+=1;
            }
        }

        return value;
    }
};