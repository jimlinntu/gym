class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] == the longest increasing subsequence ending at i
        vector<int> dp(n, 1);
        int ans = 1;
        dp[0] = 1; // itself
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
