class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // dp[i] == the minimum cost to reach ith step (cost[i-1])
        vector<int> dp(3);
        dp[1] = cost[0];
        dp[2] = cost[1];
        for(int i = 3; i <= n; i++){
            dp[i%3] = min(dp[(i-1)%3], dp[(i-2)%3]) + cost[i-1];
        }
        // The last hop require no cost
        return min(dp[(n+1-1)%3], dp[(n+1-2)%3]);
    }
};
