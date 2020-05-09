/*
 * O(nm) time
 * O(nm) space
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        // a padded dp table (n+1) x (m+1)
        // define dp[i][j] == whether s_1:i match p_1:j
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        assert(dp.size() == n+1 && dp[0].size() == m+1);
        // Initialized dp table
        // because an empty pattern must match an empty string
        dp[0][0] = true;
        // However, for any dp[i][0] where i > 0 must be false because an empty pattern cannot match a string with its length > 0
        
        // Initialized dp[0][j] with j > 0
        for(int j = 1; j <= m; j++){
            if(p[j-1] == '*'){
                // this char* must be empty!
                dp[0][j] = dp[0][j-2]; // jump two chars backward
            }else{
                dp[0][j] = false; // Cuz the string is empty
            }
        }
        
        // dp
        // dp(s_1:i, ?)
        for(int i = 1; i <= n; i++){
            // dp(s_1:i, p_1:j)
            for(int j = 1; j <= m; j++){
                if(p[j-1] == '*'){
                    // If a Kleene star appears,
                    // these must be a character followed by *
                    assert(j - 2 >= 0);
                    if(p[j-2] == '.' || p[j-2] == s[i-1]){
                        // this char* can be expanded as:
                        // 1. empty, 2. one, 3. multiple
                        dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                    }else{
                        // this must be empty!
                        dp[i][j] = dp[i][j-2];
                    }
                }else if(p[j-1] == '.' || p[j-1] == s[i-1]){
                    // this character must be matched!
                    dp[i][j] = dp[i-1][j-1];                    
                }else{
                    // this pattern cannot match this string
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
