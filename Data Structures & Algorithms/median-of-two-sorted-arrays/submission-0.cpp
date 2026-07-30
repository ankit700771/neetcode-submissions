class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>ans(n1+n2, 0);
        int i = 0;
        int j = 0;
        int k = 0;

        while(i < n1 && j < n2) {
            if(nums1[i] <= nums2[j]) {
                ans[k++] = nums1[i++];
            } else {
                ans[k++] = nums2[j++];
            }
        }

        while(i < n1) {
            ans[k++] = nums1[i++];
        }

        while(j < n2) {
            ans[k++] = nums2[j++];
        }

        if((n1+n2) % 2 == 0) {
            int mid = (n1 + n2) / 2;

            return (ans[mid -1] + ans[mid]) / 2.0;
        } else {
            return ans[(n1 + n2) / 2.0];
        }
    }
};
