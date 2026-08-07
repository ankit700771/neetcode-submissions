class Solution {
public:
    string s = "";
    void solve(string &digits, vector<string>&ans, int idx, unordered_map<char, string>& umap) {
        if(idx >= digits.length()) {
            ans.push_back(s);
            return;
        }

        string temp = umap[digits[idx]];
        for(int i = 0; i<temp.size(); i++) {
            s.push_back(temp[i]);
            solve(digits, ans, idx+1, umap);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) {
            return {};
        }
        vector<string> ans;

        unordered_map<char, string> umap;

        umap['2'] = "abc";
        umap['3'] = "def";
        umap['4'] = "ghi";
        umap['5'] = "jkl";
        umap['6'] = "mno";
        umap['7'] = "pqrs";
        umap['8'] = "tuv";
        umap['9'] = "wxyz";

        solve(digits, ans, 0, umap);
        return ans;
    }
};
