class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        for(; ans < strs[0].size(); ans++){
            // if there are some differences
            bool is_same = true;
            for(int i = 1; i < n; i++){
                if(ans >= strs[i].size() or strs[i][ans] != strs[i-1][ans]){
                    is_same = false;
                    break;
                }
            }
            if(!is_same) break;
        }

        return strs[0].substr(0, ans);
    }
};
