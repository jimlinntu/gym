class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // i: prices within [0, i]
        // Two choices:
        // 1. do not trade in this day
        // 2. sell at day i
        // dp[i] == max(dp[i-1], max j(prices[i] - prices[j] + dp[j-2]))
        //       == max(dp[i-1], prices[i] - min j (prices[j] - dp[j-2]))
        // 0 <= j <= i
        // Base case:
        // dp[0] == 0

        // Comment: The main different between k transactions
        //          is that here we do not need to store transaction information!
        int n = prices.size();
        vector<int> dp(n);
        dp[0] = 0;

        int min_reduce = prices[0];        
        for(int i = 1; i < n; i++){
            if(i > 1) min_reduce = min(min_reduce, prices[i] - dp[i-2]);
            else min_reduce = min(min_reduce, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - min_reduce);
        }
        return dp[n-1];
    }
};
