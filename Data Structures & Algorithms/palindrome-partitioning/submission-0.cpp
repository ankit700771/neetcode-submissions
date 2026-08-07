class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrom(string &s, int start, int end) {
        while(start <= end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }

    void solve(string &s, vector<string>& curr, int idx) {
        if(idx >= s.size()) {
            result.push_back(curr);
            return;
        }

        /**
            -- the logic is very simple we have partion a string at every index first we start from 0th index then we 
                choose all the possible string that are start with index 0 and have the pailindrom 

            -- that's why we need a for loop if you look closely then you realise that from loop start is fixed and move end
                for corresponding index


        */

        for(int i = idx; i<s.size(); i++) {
            if(isPalindrom(s, idx, i)) { // here we check that the string or choosen string is allready palindrom
                curr.push_back(s.substr(idx, i-idx+1)); // here starting index whould be idx and i become end
                solve(s, curr, i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>curr;
        solve(s, curr, 0);

        return result;        
    }
};
