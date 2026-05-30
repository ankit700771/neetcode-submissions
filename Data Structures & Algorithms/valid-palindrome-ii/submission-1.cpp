class Solution {
public:

    bool checkPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        if(s.size() == 1) return true;

        if(checkPalindrome(s)) {
            return true;
        }

        for(int i = 0; i<s.size()-1; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i+1, s.size());

            string ans = left + right;

            if(checkPalindrome(ans)) {
                return true;
            }
        }

        return false;
    }
};