class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for(int r: rods) sum += r;
        // dp[i][d] == the maximum length of the longest steel(steel1)
        //             by using [0, i) rods,
        //             and steel1-steel0 == d
        // initially, -1 means inreachable
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        // not using any rod
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            int r = rods[i-1];
            for(int d = 0; d <= sum; d++){
                // not use this rod
                dp[i][d] = dp[i-1][d];
                // Put this rod at steel1 (longer one)
                if(d-r >= 0 and dp[i-1][d-r] != -1)
                    dp[i][d] = max(dp[i][d], dp[i-1][d-r]+r);
                // Put this rod at steel0 and steel0 <= steel1
                if(d+r <= sum and dp[i-1][d+r] != -1)
                    dp[i][d] = max(dp[i][d], dp[i-1][d+r]);
                // Put this rod at steel0 and steel0 > steel2
                if(r-d >= 0 and dp[i-1][r-d] != -1)
                    dp[i][d] = max(dp[i][d], dp[i-1][r-d]+d);
            }
        }
        if(dp[n][0] == -1) return 0;
        else return dp[n][0];
    }
};
