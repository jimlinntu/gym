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

        // DP over i direction
        vector<int> dp(2+1, 0);
        vector<int> min_reduce(2+1, prices[0]); // when j == 0

        for(int i = 1; i < n; i++){
            // NOTE: because we need dp[k-1][j-1]
            //       we have to compute from 2 to 1
            for(int k = 2; k >= 1; k--){
                // compute min over j (prices[j] - dp[k-1][j-1])
                // => prices[j] - dp[k-1][j-1]
                min_reduce[k] = min(min_reduce[k], prices[i] - dp[k-1]);
                // dp[k][i] == max(dp[k][i-1], prices[i] - min_reduce[k])
                dp[k] = max(dp[k], prices[i] - min_reduce[k]);
            }
        }
        return dp[2];
    }
};
