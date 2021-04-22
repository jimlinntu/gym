class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int maxval = -1;
        if(n <= 3){
            for(int num: nums) maxval = max(maxval, num);
            return maxval;
        }
        // The maximum amount we can rob ==
        // max(the max we can rob in [0,n-2],
        //     the max we can rob in [1,n-3] + nums[n-1])
        // 1. Compute [0, n-2]
        vector<int> dp(n, 0);
        int not_rob = -1;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n-1; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        not_rob = dp[n-2];
        // 2. Compute [1, n-3] + nums[n-1]
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for(int i = 3; i < n-2; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        // Whether to rob nums[n-1] (no or yes)
        return max(not_rob, dp[n-3] + nums[n-1]);
    }
};
