class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        // Observe:
        // at amount x
        // we can decide to use coins[0], coins[1], coins[2] ...
        // Say after deciding to use coins[0]
        // That leaves us x-coins[0]
        // If we already know what's the minimum number of coins for x-coins[0]
        // we immediately know the answer!
        assert(amount >= 0);
        // dp[i] == the minimum number of coins to achieve
        vector<int> dp(amount+1, -1);
        int coin_n = 0;
        dp[0] = 0;
        for(int i = 0; i < coins.size() and coins[i] <= amount; i++, coin_n++){
            dp[coins[i]] = 1; // just use 1 coin
        }
        // O(amount * coin_n)
        for(int amt = 1; amt <= amount; amt++){
            if(dp[amt] != -1) continue; // already knew
            for(int j = 0; j < coin_n and amt >= coins[j]; j++){
                if(dp[amt-coins[j]] == -1) continue; // no way
                if(dp[amt] == -1) dp[amt] = dp[amt-coins[j]]+1;
                else dp[amt] = min(dp[amt], dp[amt-coins[j]]+1);
            }
        }
        return dp[amount];
    }
};
