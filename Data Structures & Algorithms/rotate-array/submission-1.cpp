class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int actual_k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + actual_k);
        reverse(nums.begin() + actual_k, nums.end());
    }
};