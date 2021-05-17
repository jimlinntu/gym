class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] == the minimum path sum when we end at (i, j)
        //          == grid[i][j] + min(dp[i-1][j], do[i][j-1])
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        dp[0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[i] = grid[0][i] + dp[i-1];
        }
        for(int i = 1; i < m; i++){
            dp[0] = dp[0] + grid[i][0];
            for(int j = 1; j < n; j++){
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        return dp[n-1];
    }
};
