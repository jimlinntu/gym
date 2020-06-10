class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        // dp[i][j] = the length of the LCS between sorted[0:i) and nums[0:j)
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // Initialize dp[0][j] = 0, dp[i][0] = 0
        for(int i = 1; i <= n; i++){
            // avoid duplicates
            if(i > 1 and sorted[i-1] == sorted[i-2]){
                // just copy from dp[i-1][*]
                for(int j = 1; j <= n; j++){
                    dp[i][j] = dp[i-1][j];
                }
                continue;
            }
            // normal dp
            for(int j = 1; j <= n; j++){
                if(sorted[i-1] == nums[j-1]){
                    dp[i][j] = max(max(dp[i-1][j-1]+1, dp[i][j-1]), dp[i-1][j]);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};

