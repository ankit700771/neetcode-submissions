class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int sizeOfWord1 = word1.size();
        int sizeOfWord2 = word2.size();
        int i = 0;
        int j = 0;

        while(i < sizeOfWord1 && j < sizeOfWord2) {
            ans += word1[i++];
            ans += word2[j++];
        }

        ans += word1.substr(i);
        ans += word2.substr(j);

        return ans;
        
    }
};