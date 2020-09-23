class Solution {
public:
    int dp[1000][1000];
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return s;
        int best_x = -1, best_len = -1;
        for(int len = 1; len <= n; len++){
            // dp(x, y)
            for(int i = 0; i <= n-len; i++){
                int x = i, y = i+len-1;
                // if s[x] != s[y], then dp(x, y) must be false!
                // if s[x] == s[y], then we still need to check whether
                // dp(x+1, y-1) is also a palindrome
                // if len <= 3, we do not need to check
                // Ex. aba, aa, b
                dp[x][y] = (s[x] == s[y]) && (len <= 3 || dp[x+1][y-1]);
                // if string s: [x, y] is a palindrome
                if(dp[x][y] and len > best_len){
                    best_x = x;
                    best_len = len;
                }
            }
        }
        return s.substr(best_x, best_len);
    }
};
