class Solution {
public:

    bool checkPalindrome(string s, int i, int j) {
        int start = i;
        int end = j;

        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        if(s.size() == 1) return true;

        int start = 0;
        int end = s.size() - 1;

        while(start <= end) {
            if(s[start] != s[end]) {
                bool ans1 = checkPalindrome(s, start+1, end);
                bool ans2 = checkPalindrome(s, start, end-1);
                if(ans1 || ans2) {
                    return true;
                } else {
                    return false;
                }
            }
            start++;
            end--;
        }

        return true;
    }
};