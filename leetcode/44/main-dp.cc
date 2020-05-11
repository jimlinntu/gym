class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(2, vector<bool>(m+1));
        // Define: dp[i][j] as whether s_1:i can be matched by p_1:j
        // Base case:
        //  dp[0][0] = true: the empty pattern can match the empty string
        //  dp[0][j > 0] = dp[0][j-1] if p_j == "*" else false
        //  dp[i > 0][0] = false: empty pattern cannot match any non empty string
        dp[0][0] = true;
        for(int j = 1; j <= m; j++){
            if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
            else dp[0][j] = false;
        }
        // Dynamic Programming
        for(int i = 1; i <= n; i++){
            // Base case:
            dp[i%2][0] = false; // dp[i > 0][0] = false
            for(int j = 1; j <= m; j++){
                if(s[i-1] == p[j-1] or p[j-1] == '?'){
                    // p_j must match s_i
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                }else if(p[j-1] == '*'){
                    // empty or expansion
                    dp[i%2][j] = dp[(i-1)%2][j] or dp[i%2][j-1];
                }else{
                    // this p_j cannot match s_i
                    dp[i%2][j] = false;
                };
            }
        }
        return dp[n%2][m];
    }
};
