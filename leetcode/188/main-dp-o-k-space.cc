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
        vector<int> dp(k+1, 0);
        // when q == 0
        vector<int> min_reduce(k+1, prices[0]);
        
        // Loop over direction j
        for(int j = 1; j < n; j++){
            for(int i = k; i >= 1; i--){
                min_reduce[i] = min(min_reduce[i], prices[j]-dp[i-1]);
                dp[i] = max(dp[i], prices[j] - min_reduce[i]);
            }
        }
        return dp[k];
    }
};
