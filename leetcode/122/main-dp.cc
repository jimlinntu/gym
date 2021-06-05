class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i] == the maximum profit I can get from [0, i]
        //       == not doing anything on i or sell at i
        //       == max(dp[i-1],
        //          max_j(dp[j-1] + prices[i] - prices[j]) <-- buy at j sell at i
        // where j < i
        // Observe:
        //    max_j(dp[j-1] + prices[i] - prices[j])
        // == prices[i] + max_j(dp[j-1] - prices[j])
        int n = prices.size();
        vector<int> dp(n);
        int secondterm;
        dp[0] = 0;
        secondterm = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1]; // not doing anything on i
            dp[i] = max(dp[i], prices[i] + secondterm);
            secondterm = max(secondterm, dp[i-1] - prices[i]);
        }
        return dp[n-1];
    }
};
