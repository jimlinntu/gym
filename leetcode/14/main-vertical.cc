class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        int min_len = INT_MAX;
        for(int i = 0; i < n; i++){
            min_len = min(min_len, (int)strs[i].length());
        }
        for(; ans < min_len; ans++){
            // if there are some differences
            bool is_same = true;
            for(int i = 1; i < n; i++){
                if(strs[i][ans] != strs[i-1][ans]){
                    is_same = false;
                    break;
                }
            }
            if(!is_same) break;
        }

        return strs[0].substr(0, ans);
    }
};
