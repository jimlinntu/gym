class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        // dp[i][j] == dp[i-1][j] + dp[i][j-1]
        // either comes from up or left
        // And this can trivially reduce to O(n) space
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};
