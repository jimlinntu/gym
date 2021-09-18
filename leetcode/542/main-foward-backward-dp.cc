struct E{
    int x, y, d;
};
class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX-1));
        // Forward DP (from left and top)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min((i > 0 and dp[i-1][j] != INT_MAX)?dp[i-1][j]+1:INT_MAX,
                                   (j > 0 and dp[i][j-1] != INT_MAX)?dp[i][j-1]+1:INT_MAX);
            }
        }
        // Backward DP (from bottom and right)
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min({dp[i][j], (i+1 < m and dp[i+1][j] != INT_MAX)? dp[i+1][j]+1: INT_MAX,
                                   (j+1 < n and dp[i][j+1] != INT_MAX)? dp[i][j+1]+1: INT_MAX});
            }
        }
        return dp;
    }
};
