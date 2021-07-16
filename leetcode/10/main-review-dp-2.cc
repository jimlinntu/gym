class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size(); // directly treat * as a char
        int n = s.size();
        // dp[i][j] == p[0]~p[i-1] matches 
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        // dp[0][j > 0] = false
        // dp[i > 0][0] = depends
        for(int i = 1; i <= m; i++){
            bool is_wild = p[i-1] == '*';
            // dp[i][0]
            if(is_wild) dp[i][0] = dp[i-2][0]; // jump two backward
            else dp[i][0] = false; // cannot match a empty string

            for(int j = 1; j <= n; j++){
                if(is_wild){
                    // Case 1: Match it and step back
                    // Case 2: Match it and stay
                    // Case 3: not match it
                    if(p[i-2] == '.' or p[i-2] == s[j-1])
                        dp[i][j] = dp[i-2][j-1] or dp[i][j-1] or dp[i-2][j];
                    else dp[i][j] = dp[i-2][j]; // not match it
                }else{
                    if(p[i-1] == '.' or p[i-1] == s[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};
