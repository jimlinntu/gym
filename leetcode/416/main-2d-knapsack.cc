class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int num: nums) s += num;
        // if the sum is odd, then we are not possible to find two subsets
        if(s % 2) return false;
        int target = s / 2;
        int n = nums.size();
        if(n < 1) return false;
        // dp[i][target] ==
        // whether we can achieve sum == target when using nums from 0~i-1
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        for(int i = 0; i <= n; i++) dp[i][0] = true;
        int cursum = 0;
        for(int i = 1; i <= n; i++){
            cursum += nums[i-1];
            // We are only interested in the sum <= cursum and sum <= target
            int bound = min(cursum, target);
            for(int j = 0; j <= bound; j++){
                // use it or not
                dp[i][j] = dp[i-1][j];
                if(j-nums[i-1] >= 0) dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
            }
        }

        // We want to know dp[n][target]
        return dp[n][target];
    }
};
