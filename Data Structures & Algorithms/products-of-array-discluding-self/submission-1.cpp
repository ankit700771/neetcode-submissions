class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        int prod = 1;
        int pos = -1;
        int zeroCount = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zeroCount++;
                pos = i;
            } else {
                prod *= nums[i];
            }
        }

        if(zeroCount >= 2) {
            return ans;
        }

        if( zeroCount == 1) {
            ans[pos] = prod;
            return ans;
        }

        for(int i = 0; i<n; i++) {
            ans[i] = prod / nums[i];
        }
        return ans;



    }
};
