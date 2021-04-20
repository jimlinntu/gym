class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        vector<int> psum(n+1, 0);
        for(int i = 0; i < n; i++){
            psum[i+1] = psum[i] + nums[i];
        }
        // DP step:
        // dp[i][m] == the min largest sum of [0, i] with m subarrays
        //          == min j (sum(j+1~i) + dp[j][m-1])
        // Base cases: dp[i][1]
        for(int i = 0; i < n; i++){
            dp[i][1] = psum[i+1] - psum[0];
        }
        // O(m n^2)
        for(int i = 0; i < n; i++){
            // [0, i] with mm subarrays
            for(int mm = 2; mm <= m; mm++){
                // dp[j][mm-1] cannot form mm-1 subarrays
                // j should be at least mm-2 so that it can form mm-1 subarrays
                for(int j = mm-1-1; j < i; j++){
                    assert(dp[j][mm-1] != -1);
                    // sum(j+1~i)
                    int val = max(psum[i+1] - psum[j+1], dp[j][mm-1]);
                    if(dp[i][mm] == -1) dp[i][mm] = val;
                    else dp[i][mm] = min(dp[i][mm], val);
                }
            }
        }
        // [0, n-1] with m subarrays
        return dp[n-1][m];
    }
};
