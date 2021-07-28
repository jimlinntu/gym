class Solution {
public:
    int robber_1(vector<int> &nums, int start, int end,
                 vector<int> &dp){
        if(start >= end) return 0;
        int n = end - start;
        dp[start] = nums[start];
        if(n >= 2)
            dp[start+1] = max(nums[start], nums[start+1]);
        for(int i = start+2; i < end; i++){
            // rob or not
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[end-1];
    }
    int rob(vector<int>& nums) {
        // whether to rob the last house
        // Ex. a b c d e f g
        //     x         x ^ rob it     --> normal dp on b to f
        //                 x not rob it --> normal dp on a to f
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n);
        // rob the last or not
        return max(robber_1(nums, 1, n-2, dp)+nums.back(),
                   robber_1(nums, 0, n-1, dp));
    }
};
