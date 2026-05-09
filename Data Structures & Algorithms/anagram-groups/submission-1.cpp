class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>res;
        for(auto s: strs) {
            vector<int>count(26, 0);
            for(auto ch: s) {
                count[ch - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i<26; i++) {
                key += ',' + to_string(count[i]);
            }

            res[key].push_back(s);
        }

        vector<vector<string>>result;
        for(auto &r: res) {
            result.push_back(r.second);
        }
        return result;
    }
};
