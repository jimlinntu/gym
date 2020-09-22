class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1; // dp(i, i) == 1
        }
        // dp over lengths
        for(int l = 2; l <= n; l++){
            for(int i = 0; i <= n-l; i++){
                // compute: dp(x, y): the longest palindrome length within [x, y]
                int x = i, y = i+l-1;
                assert(y < n);
                if(s[x] == s[y]){
                    // dp(x, y) = dp(x+1, y-1) + 2
                    dp[x][y] = dp[x+1][y-1] + 2;
                }else{
                    // dp(x, y) = max(dp(x+1, y), dp(x, y-1))
                    dp[x][y] = max(dp[x+1][y], dp[x][y-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
