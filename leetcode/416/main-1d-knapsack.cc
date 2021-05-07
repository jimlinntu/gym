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
        
        vector<bool> dp(target+1, false);
        // Complexity: O(n * target)
        // Initially, dp[0] represents whether we can achieve 0 sum by using non nums
        dp[0] = true;
        for(int i = 1, cursum = 0, bound; i <= n; i++){
            cursum += nums[i-1];
            // If we only have cursum now, we can only fill up to cursum
            bound = min(cursum, target);
            for(int w = bound; w >= 0; w--){
                dp[w] = dp[w]; // useless, but demonstrate: not using nums[i-1]
                // Use nums[i-1] to fill the sum
                if(w-nums[i-1] >= 0) dp[w] = dp[w] or dp[w-nums[i-1]];
            }
        }
        return dp[target];
    }
};
