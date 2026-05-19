class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(nums.begin(), nums.end());
        int max_len = 0;

        for(int i = 0; i<nums.size(); i++) {
            int currnt_num = nums[i];
            int len = 0;
            if(st.find(currnt_num-1) == st.end()) {
                while(st.find(currnt_num) != st.end()) {
                    currnt_num++;
                    len++;
                }
                max_len = max(max_len, len);
            }
        }

        return max_len;
    }
};
