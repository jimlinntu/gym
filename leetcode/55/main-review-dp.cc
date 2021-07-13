class Solution {
public:
    bool canJump(vector<int>& nums) {
        // define dp[i] == whether i can reach the last index
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n-1] = true;
        // dp[i] == OR({dp[i+j]}) where 1 <= j <= nums[i]
        for(int i = n-2; i >= 0; i--){
            int num_steps = nums[i];
            // if dp[i] == true, early break
            for(int j = 1; j <= num_steps and i+j < n and !dp[i]; j++){
                dp[i] = dp[i] or dp[i+j];
            }
        }
        return dp[0];
    }
};
