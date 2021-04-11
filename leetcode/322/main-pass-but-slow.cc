class Solution {
public:
    unordered_map<int, int> cache;
    int dp(int amt, vector<int> &coins){
        // dp(amt) == the fewest number of coins for amt
        // time complexity: O(coins.size() * amt)
        if(amt == 0) return 0;
        auto it = cache.find(amt);
        if(it != cache.end()) return it->second;
        int minimum = -1;
        for(int i = 0; i < coins.size(); i++){
            if(amt - coins[i] >= 0){
                int val = dp(amt-coins[i], coins);
                if(val == -1) continue;
                if(minimum == -1) minimum = 1+val;
                else minimum = min(minimum, 1+val);
            }
        }
        cache[amt] = minimum;
        return minimum;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return dp(amount, coins);
    }
};
