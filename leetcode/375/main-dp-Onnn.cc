class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j] == the minimum amount of money you need to pay
        //             when you already know the number is in [i, j] range
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[i][i+1] == 0 because we already know this must the number
        // dp[i][j] == min over k (k + max(dp[i][k-1], dp[k+1][j]))
        // O(n^2) * O(n) == O(n^3)
        for(int len = 2; len <= n; len++){
            for(int i = 1; i <= n-len+1; i++){
                int j = i + len - 1;
                // [i, j]
                dp[i][j] = min(i + dp[i+1][j], j + dp[i][j-1]);
                for(int k = i+1; k < j; k++){
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k-1], dp[k+1][j]));
                }
            }
        }
        // dp[1][n] == [1, n] the mininum amount of money you need to pay
        return dp[1][n];
    }
};
