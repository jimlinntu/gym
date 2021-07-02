class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int max_len = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            // expand around: <--   i   -->
            // expand around: <-- i,i+1 -->
            int l = i, r = i;
            while(0 <= l and r < n and s[l] == s[r]){
                l--, r++;
            }
            if(r - l - 1 > max_len){
                max_len = r-l-1;
                ans = s.substr(l+1, r-l-1);
            }
            l = i, r = i+1;
            if(r >= n) continue;
            while(0 <= l and r < n and s[l] == s[r]){
                l--, r++;
            }
            if(r - l - 1 > max_len){
                max_len = r-l-1;
                ans = s.substr(l+1, r-l-1);
            }
        }
        return ans;
    }
};
