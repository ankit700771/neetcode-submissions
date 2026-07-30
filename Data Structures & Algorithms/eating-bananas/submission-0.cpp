class Solution {
public:

    int isValid(vector<int>& piles, int mid , int h) {
        int time = 0;

        for(int i = 0; i<piles.size(); i++) {
            time +=  ceil((double)piles[i] / mid);
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            int actual_time = isValid(piles, mid, h);

            if(actual_time <= h) {
                ans = min(ans, mid);
                end = mid - 1;
            } else if(actual_time > h) {
                start = mid + 1;
            }

        }

        return ans;
    }
};
