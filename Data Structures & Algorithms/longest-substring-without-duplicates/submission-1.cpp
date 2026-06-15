class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>umap;
        int start = 0;
        int end = 0;
        int n = s.size();
        int maxLength = 0;
        while(end < n) {
            if(umap.find(s[end]) != umap.end()) {
                umap.erase(s[start]);
                start++;
            } else {
                maxLength = max(maxLength, end - start + 1);
                umap[s[end]] = end;
                end++;
            }
            
        }

        return maxLength;

    }
};
