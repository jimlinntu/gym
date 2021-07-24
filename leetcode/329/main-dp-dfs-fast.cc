class Solution {
public:
    int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    int dfs(int x, int y, vector<vector<int>> &matrix, int dp[200][200]){
        if(dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 1; // itself
        for(int d = 0; d < 4; d++){
            int nx = x + dir[d][0], ny = y + dir[d][1];
            if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
            if(matrix[x][y] >= matrix[nx][ny]) continue;
            // tell me the maximum depth of you
            // then I can update my maximum depth
            dp[x][y] = max(dp[x][y], 1+dfs(nx, ny, matrix, dp));
        }
        return dp[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int dp[200][200];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        int ans = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }
};
