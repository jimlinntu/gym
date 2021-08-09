class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for(int r: rods) sum += r;
        // dp[i][sum] == maximum sum(rods has +1 signs) 
        //               if by using first i rods, we can sum up to `sum`
        //               using +1, -1, 0
        // Recursion:
        // dp[i][sum] = max(dp[i-1][sum-rods[i]] + rods[i],  <--- +rods[i]
        //                  dp[i-1][sum+rods[i]],            <--- -rods[i]
        //                  dp[i-1][sum]);                   <--- 0*rods[i]
        unordered_map<int, int> dp[21];
        // not using any rods
        dp[0][0] = 0; // sum( positive rods ) == 0
        for(int i = 1; i <= n; i++){
            int r = rods[i-1];
            // NOTE: dp from i-1 to i
            for(auto it = dp[i-1].begin(); it != dp[i-1].end(); it++){
                int s = it->first;
                int positive_sum = it->second;
                
                // 0 * r: not use this rod
                if(dp[i].count(s)) dp[i][s] = max(dp[i][s], positive_sum);
                else dp[i][s] = positive_sum;
                // +1 * r: put it in the bag0
                if(dp[i].count(s+r)) dp[i][s+r] = max(dp[i][s+r], positive_sum+r);
                else dp[i][s+r] = positive_sum+r;
                // -1 * r: put it in the bag1
                if(dp[i].count(s-r)) dp[i][s-r] = max(dp[i][s-r], positive_sum);
                else dp[i][s-r] = positive_sum;
            }
        }
        return dp[n][0];
    }
};
