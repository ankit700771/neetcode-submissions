class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int sizeOfWord1 = word1.size();
        int sizeOfWord2 = word2.size();
        for(int i = 0; i<sizeOfWord1 || i < sizeOfWord2; i++) {
            if(i < sizeOfWord1) ans += word1[i];
            if(i < sizeOfWord2) ans += word2[i];
        }
        return ans;
        
    }
};