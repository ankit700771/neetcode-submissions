class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int maxLenght = 0;
        vector<int>count(26, 0);

        while(right < s.size()) {
            count[s[right] -'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            while((right-left+1) - maxFreq > k) {
                count[s[left] - 'A']--;
                int maxi = *max_element(count.begin(), count.end());
                maxFreq = max(maxFreq, maxi);
                left++;
            }

            if((right - left + 1) - maxFreq <= k) {
                maxLenght = max(maxLenght, right - left + 1);

            }

            right++;
        }

        return maxLenght;
    }
};
