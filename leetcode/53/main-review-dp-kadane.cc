class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // dp[i] == the largest sum ending at i
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = nums[0];
        // 
        for(int i = 1; i < n; i++){
            // dp[i] = max(nums[i], nums[i]+dp[i-1])
            // to contencate or not!
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
