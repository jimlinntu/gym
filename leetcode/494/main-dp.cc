class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // dp[i][val-(-1000)] == the number of expressions to build `val`
        //               by using 0~i-1 in `nums`
        //            == dp[i-1][val-nums[i]] + dp[i-1][val+nums[i]]
        //                    (use +)                  (use -)
        int n = nums.size();
        int dp[20+1][2001] = {0};
        int cursum = 0;
        int offset = -1000;
        // to build 0 using 0~-1 (no numbers), we have 1 choice
        // that is choosing the empty set
        dp[0][0-offset] = 1;
        // O(n * sum(nums))
        for(int i = 1; i <= n; i++){
            cursum += nums[i-1];
            for(int val = -cursum; val <= cursum; val++){
                // Choose + or - for nums[i-1]
                if(val-nums[i-1] >= -1000)
                    dp[i][val-offset] += dp[i-1][val-nums[i-1]-offset];
                if(val+nums[i-1] <= 1000)
                    dp[i][val-offset] += dp[i-1][val+nums[i-1]-offset];
            }
        }
        return dp[n][target-offset];
    }
};
