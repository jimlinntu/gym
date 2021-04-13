class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        // nums = [1, nums, 1]
        nums.insert(nums.begin(), 1); // O(n)
        nums.push_back(1);
        // dp[i][j] == the max coins we can get by first burst balloons in [i, j] first
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // Base cases:
        // dp[i][i] == nums[i-1] * nums[i] * nums[i+1]
        for(int i = 1; i <= n; i++){
            dp[i][i] = nums[i-1] * nums[i] * nums[i+1];
        }
        // Compute dp[i][j]
        // dp[i][j] =
        //     max over k (dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + dp[k+1][j])
        //     where i <= k <= j
        // Note: 
        //    1. k is the last balloon to be burst.
        //       This is why nums[i-1] * nums[k] * nums[j+1] is in the middle
        //    2. i <= j
        // DP over length
        // O(n^3)
        for(int len = 2; len <= n; len++){
            for(int i = 1; i <= n-len+1; i++){
                int j = i+len-1;
                // [i, j]
                // boundary conditions:
                // 1. i is last burst 2. j is last burst
                dp[i][j] = max(nums[i-1] * nums[i] * nums[j+1] + dp[i+1][j],
                               dp[i][j-1] + nums[i-1] * nums[j] * nums[j+1]);
                for(int k = i+1; k <= j-1; k++){
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1]
                                 + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
