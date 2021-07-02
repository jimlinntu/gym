class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        int freq[26];
        for(string &s: strs){
            //------------------------------------------------
            fill(freq, freq+26, 0);
            // Encode a string using its frequence map
            for(char c: s) freq[c-'a']++;
            string standard;
            for(int i = 0; i < 26; i++){
                // if a string is incredibly long, this can mitigate it effectively
                // Ex. aaaaaaaaaaabcd
                // 11a1b0c1d
                standard += to_string(freq[i]);
                standard.push_back(i+'a');
            }
            //------------------------------------------------
            map[standard].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it = map.begin(); it != map.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
