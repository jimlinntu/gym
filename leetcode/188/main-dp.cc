class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // Define DP
        // i: the number of transactions we used
        // j: prices within [0, j]
        // Two choices: 1. do not sell at day j 2. make a transaction (buy at j, sell at q)
        // dp[i][j] == max(dp[i][j-1], max q (prices[j]-prices[q]+dp[i-1][q-1]))
        //          == max(dp[i][j-1], prices[j] - min q(prices[q]-dp[i-1][q-1]))
        // where 0 <= q <= j
        // Base case:
        // dp[0][j] == 0
        // dp[i][0] == 0
        int n = prices.size();
        if(k == 0) return 0;
        if(n == 0) return 0;
        vector<vector<int>> dp(k+1, vector<int>(n, 0));

        for(int i = 1; i <= k; i++){
            int min_reduce = prices[0];
            for(int j = 1; j < n; j++){
                min_reduce = min(min_reduce, prices[j]-dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j] - min_reduce);
            }
        }
        return dp[k][n-1];
    }
};
