class Solution {
public:
    int numSquares(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        // Bottom up DP
        for(int i = 1; i <= n; i++){
            int upper = (int)sqrt(i);
            for(int j = upper; j > 0; j--){
                if(dp[i] == -1) dp[i] = dp[i - j*j]+1;
                else dp[i] = min(dp[i - j*j]+1, dp[i]);
            }
        }
        return dp[n];
    }
};
