class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        int n = strs.size();
        for(int i = 0; i < n; i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            hashmap[sorted].push_back(strs[i]);
        }
        int i = 0;
        vector<vector<string>> ans(hashmap.size());
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            ans[i++] = it->second; // copy the whole list
        }
        return ans;
    }
};
