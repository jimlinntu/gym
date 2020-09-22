class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return string();
        // Define:
        // dp(i, j) == the longest palindromic 'substring' (not subsequence) length
        //             within [i, j]
        // s[0:0] must be a valid palindromic
        int best_x = 0, best_y = 0;
        int best_len = 1;
        vector<vector<int>> dp(n, vector<int>(n));
        // Base case: length == 1
        for(int i = 0; i < n; i++){
            dp[i][i] = 1; // dp(i, i)
        }
        // dp over lengths
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int x = i, y = i+len-1;
                // sx, |sx+1, sx+2 ... sy-1|, sy
                // if dp(x+1, y-1) != len-2, we cannot update it!
                if(s[x] == s[y] && dp[x+1][y-1] == len-2){
                    dp[x][y] = len;
                }else{
                    dp[x][y] = max(dp[x+1][y], dp[x][y-1]);
                }
                // track the best length!
                if(dp[x][y] > best_len){
                    best_len = dp[x][y];
                    best_x = x, best_y = y;
                }
            }
        }
        return s.substr(best_x, best_y - best_x + 1);
    }
};
