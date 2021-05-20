class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // dp[i][j][q] == the maximum cherries they can pick
        //                when they end at (i, j)(first bot) and (p ==i, q)(second bot)
        vector<vector<vector<int>>> dp(m, 
                                       vector<vector<int>>(n,
                                       vector<int>(n, -1)));
        assert(n > 1);
        // dp((0, 0), (0, n-1)) == grid[i][j] + grid[p][q];
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        // DP over rows
        int ans = dp[0][0][n-1];
        int d[3] = {-1, 0, 1};
        // O(m * n^2 * 9) = O(mn^2)
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int q = 0, p; q < n; q++){
                    p = i;
                    // 9 possibilities:
                    // (i-1, j-1, q-1)
                    // (i-1, j-1, q)
                    // (i-1, j-1, q+1)
                    // (i-1, j, q-1)
                    // (i-1, j, q)
                    // (i-1, j, q+1)
                    // (i-1, j+1, q-1)
                    // (i-1, j+1, q)
                    // (i-1, j+1, q+1)
                    for(int k = 0; k < 3; k++){
                        for(int l = 0; l < 3; l++){
                            if(j + d[k] < 0 or j + d[k] >= n
                                    or q + d[l] < 0 or q + d[l] >= n) continue;

                            dp[i][j][q] = max(dp[i][j][q], dp[i-1][j+d[k]][q+d[l]]);
                        }
                    }
                    // Two robots cannot end at (i, j), (p, q)
                    if(dp[i][j][q] == -1) continue;
                    if(i == p and j == q) dp[i][j][q] += grid[i][j];
                    else dp[i][j][q] += grid[i][j] + grid[p][q];
                    ans = max(dp[i][j][q], ans);
                }
            }
        }

        return ans;
    }
};
