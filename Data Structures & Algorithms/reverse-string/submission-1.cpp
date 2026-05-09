class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0; 
        int end = s.size() - 1;

        while(i < end) {
            swap(s[i], s[end]);
            i++;
            end--;
        }
    }
};