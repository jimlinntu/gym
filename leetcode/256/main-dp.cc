class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // colors: a b c
        //
        // 0 1 2 3 4 5 6
        //             ^
        //             a -> will incur costs[6][a] and we cannot put a at[5] 
        // This prompt me perhaps we can solve it via dp[i][color]
        // because we have to know the last color of the previous subproblem
        // dp[i][a] = min(
        //            dp[i-1][b] + costs[i][a],
        //            dp[i-1][c] + costs[i][a]);
        // dp[i][b] = min(dp[i-1][a], dp[i-1][c]) + costs[i][b]
        int n = costs.size();
        if(n == 0) return 0;
        vector<array<int, 3>> dp(n);
        for(int c = 0; c < 3; c++){
            dp[0][c] = costs[0][c];
        }
        for(int i = 1; i < n; i++){
            for(int c = 0; c < 3; c++){
                // paint this house by color c (incurs costs[i][c])
                dp[i][c] = min(dp[i-1][(c+1)%3], dp[i-1][(c+2)%3]) + costs[i][c];
            }
        }
        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};
