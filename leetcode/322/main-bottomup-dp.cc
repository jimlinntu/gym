class Solution {
public:
    int dp(int amt, vector<int> &coins){
        // dp(amt) == the fewest number of coins for amt
        // time complexity: O(coins.size() * amt)
        vector<int> table(amt+1, -1);
        int n = coins.size();
        // Base cases:
        table[0] = 0;
        for(int i = 0; i < n; i++){
            if(coins[i] > amt) break;
            table[coins[i]] = 1;
        }
        // DP
        int minimum = -1;
        for(int i = 1; i <= amt; i++){
            if(table[i] != -1) continue;
            minimum = -1;
            // dp(i) == 1 + min( dp(i-coins[j]) for all j)
            for(int j = 0; j < n; j++){
                // if there is a feasible solution
                if(i - coins[j] < 0) break;
                int val = table[i-coins[j]];
                if(val == -1) continue; // infeasible solution
                if(minimum == -1) minimum = 1+val;
                else minimum = min(minimum, 1+val);
            }
            table[i] = minimum;
        }
        return table[amt];
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return dp(amount, coins);
    }
};
