class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int length = s1.size();

        for(int i = 0; i<s2.size() - length + 1;  i++) {
            string str = s2.substr(i , length);
            sort(str.begin(), str.end());
            if(str == s1) {
                return true;
            }
        }

        return false;
    }
};
