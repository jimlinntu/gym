using ULL = unsigned long long int;
class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j] == 
        // # of distinct subsequences of s[0:i) and t[0:j)
        // dp[i][j] == match t[j-1] to s[i-1] or
        //             delete s[i-1]
        int m = s.size(), n = t.size();
        vector<vector<ULL>> dp(m+1, vector<ULL>(n+1, 0));
        // "" can match ""
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            // "" cannot have a subseq == t
            dp[0][i] = 0;
        }
        // DP step
        for(int i = 1; i <= m; i++){
            // s[0:i) can match "" by deleting all characters
            dp[i][0] = 1;
            for(int j = 1; j <= n; j++){
                // to match
                if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
                // or not to match
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
