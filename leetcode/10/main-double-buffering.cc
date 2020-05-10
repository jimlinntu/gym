/*
 * O(nm) time
 * O(2m) space
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        // two padded dp tables (m+1) == dp table with (n+1) x (m+1) implicitly
        // define dp[i](implicit)[j] == whether s_1:i match p_1:j
        vector<vector<bool>> dp(2, vector<bool>(m+1, false));  // dp[0] and dp[1] is enough!
        // Initialized dp[0][j]
        dp[0][0] = true;
        for(int j = 1; j <= m; j++){
            if(p[j-1] == '*'){
                // this char* must expand to empty string
                dp[0][j] = dp[0][j-2];
            }else{
                // impossible to match the empty string
                dp[0][j] = false;
            }
        }
        // Initialized dp[i > 0][0] (the empty pattern cannot match s_1:i)
        dp[1][0] = false;
        
        // dp by double buffering (I learned it from Parallel Programming!)
        for(int i = 1; i <= n; i++){
            // Set dp[i > 0][0] == false
            // because s_1:i cannot be matched by empty pattern!
            dp[i%2][0] = false;
            // backward updating fashion
            for(int j = 1; j <= m; j++){
                if(p[j-1] == '*'){
                    if(p[j-2] == '.' || p[j-2] == s[i-1]){
                        // empty, one, multiple
                        dp[i%2][j] = dp[i%2][j-2] || dp[i%2][j-1] || dp[(i-1)%2][j];
                    }else{
                        // this p_j* must be empty!
                        dp[i%2][j] = dp[i%2][j-2]; // two steps lookahead
                    }
                }else if(p[j-1] == '.' || p[j-1] == s[i-1]){
                    // this p_j must match s_i
                    dp[i%2][j] = dp[(i-1)%2][j-1]; // implicitly equal to dp[i-1][j-1]
                }else{
                    // this p_1:j cannot match s_1:i!
                    dp[i%2][j] = false;
                }
            }
        }
        return dp[n%2][m];
    }
};
