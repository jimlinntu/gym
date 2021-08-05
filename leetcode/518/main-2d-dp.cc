class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        
        // dp[i][amt] == the number ways to make up `amt` using coins[0]~coins[i]
        // recursion:
        // dp[i][amt] == sum(dp[i-1][amt-k*coins[i]])
        int n = coins.size();
        if(n == 0) return 0; // no coin to make up amount
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // dp[i][amt]
        dp[0][0] = 1; // there is one way to make up 0, is to not use any coin
        for(int amt = 1; amt <= amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = 1;
            else dp[0][amt] = 0;
        }
        // O(n*amount*amount)
        // Because sum(dp[i-1][amt-k*coins[i]]) will be O(amount)
        // when coins[i] == 1
        for(int i = 1; i < n; i++){
            dp[i][0] = 1; // not use any coin
            for(int amt = 1; amt <= amount; amt++){
                for(int k = 0; k*coins[i] <= amt; k++){
                    dp[i][amt] += dp[i-1][amt-k*coins[i]];
                }
            }
        }
        return dp[n-1][amount];
    }
};
