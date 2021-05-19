class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // https://leetcode.com/problems/cherry-pickup/discuss/109903/Step-by-step-guidance-of-the-O(N3)-time-and-O(N2)-space-solution
        // dp[n][i][p] == the most cherries we can pick:
        //                (0, 0) --> (i, j) and (p, q) --> (0, 0)
        // NOTE: n == i + j == p + q
        vector<vector<vector<int>>> dp(2*n-1,
                                       vector<vector<int>>(
                                       n, vector<int>(n, -1)));
        // The most cherries we can pick from (0, 0) -> (0, 0) and
        // leave from (0, 0) -> (0, 0)
        dp[0][0][0] = grid[0][0];
        for(int nn = 1; nn <= 2*n-2; nn++){
            for(int i = 0; i < n; i++){
                for(int p = 0; p < n; p++){
                    int j = nn - i, q = nn - p;
                    if(j < 0 or j >= n or q < 0 or q >= n or
                            grid[i][j] == -1 or grid[p][q] == -1){
                        dp[nn][i][p] = -1; // invalid
                    }else{
                        // (i-1, j) and (p-1, q)
                        if(i > 0 and p > 0)
                            dp[nn][i][p] = max(dp[nn][i][p], dp[nn-1][i-1][p-1]);
                        // (i-1, j) and (p, q-1)
                        if(i > 0)
                            dp[nn][i][p] = max(dp[nn][i][p], dp[nn-1][i-1][p]);
                        // (i, j-1) and (p-1, q) 
                        if(p > 0)
                            dp[nn][i][p] = max(dp[nn][i][p], dp[nn-1][i][p-1]);
                        dp[nn][i][p] = max(dp[nn][i][p], dp[nn-1][i][p]);

                        // This road might be blocked by thorns
                        if(dp[nn][i][p] < 0) continue;
                        // if (i, j) == (p, q), only count one cherry
                        if(i == p) dp[nn][i][p] += grid[i][j];
                        else dp[nn][i][p] += grid[i][j] + grid[p][q];
                    }
                }
            }
        }

        return (dp[2*n-2][n-1][n-1] == -1)? (0):(dp[2*n-2][n-1][n-1]);
    }
};
