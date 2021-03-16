class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // define:
        // i: the number of transaction we use
        // j: prices in [0, j]
        // dp[i][j] == max(dp[i][j-1], max q (prices[j] - prices[q] + dp[i-1][q-2]))
        //          == max(dp[i][j-1], prices[j] - min q (prices[q] - dp[i-1][q-2]))
        // where 0 <= q <= j
        // base cases:
        // dp[i][0] == 0
        // dp[0][j] == 0
        // if q < 2: dp[i-1][q-2] == 0
        int n = prices.size();
        // there are at most n transactions
        vector<vector<int>> dp(n+1, vector<int>(n, 0));
        for(int i = 1; i <= n; i++){
            int min_reduce = prices[0];
            for(int j = 1; j < n; j++){
                if(j > 1) min_reduce = min(min_reduce, prices[j]-dp[i-1][j-2]);
                else min_reduce = min(min_reduce, prices[j]);
                dp[i][j] = max(dp[i][j-1], prices[j] - min_reduce);
            }
        }
        return dp[n][n-1];
    }
};
