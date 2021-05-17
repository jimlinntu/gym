class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& map) {
        int m = map.size();
        int n = map[0].size();
        // dp[i][j] == dp[i-1][j] + dp[i][j-1]
        // if map[i][j] contains an obstacle, dp[i][j] = 0
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            if(map[0][i]) dp[i] = 0;
            else dp[i] = (i > 0)? (dp[i-1]):(1);
        }
        for(int i = 1; i < m; i++){
            if(map[i][0]) dp[0] = 0;
            else dp[0] = dp[0];

            for(int j = 1; j < n; j++){
                if(map[i][j]) dp[j] = 0;
                else dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};
