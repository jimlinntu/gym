class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // DP formula:
        // two choices:
        // 1. simply ignore this day
        // 2. consider there is a sell this day, loop over all possible buy date j
        // dp[k][i] == max(dp[k][i-1], max over j(prices[i] - prices[j] + dp[k-1][j-1]))
        //          == max(dp[k][i-1], prices[i] - min over j(prices[j] - dp[k-1][j-1]))
        //  where 0 <= j <= i, when j == 0, define dp[k][-1] == 0

        // dp[0][i] == 0 (because if we have no transaction to make, we cannot make profit)
        // dp[k][0] == 0 (because if we have only one day, we cannot make profit)
        vector<vector<int>> dp(2+1, vector<int>(n, 0));
        // if the number of transaction is 0, profits will be zeros
        for(int k = 1; k < 2+1; k++){
            int min_reduce = prices[0]; // when j == 0
            for(int i = 1; i < n; i++){
                // update min_reduce
                min_reduce = min(min_reduce, prices[i] - dp[k-1][i-1]);
                // do not perform transaction vs transacton at day j
                dp[k][i] = max(dp[k][i-1], prices[i] - min_reduce);
            }
        }
        return dp[2][n-1];
    }
};
