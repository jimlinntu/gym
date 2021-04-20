class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // dp[i][j][m] = min k ( max(dp[i][k][1], dp[k+1][j][m-1]))
        // where dp[k+1][j][m-1] == +inf if len([k+1, j]) < m-1
        // This indicates: [i, j]'s minimum largest sum when split into m subarrays
        vector<vector<vector<int>>> dp(n,
                                       vector<vector<int>>(n,
                                       vector<int>(m+1, -1)));
        vector<int> psum(n+1, 0);
        // Prefix sum
        for(int i = 0; i < n; i++){
            psum[i+1] = psum[i] + nums[i];
        }
        // Base case:
        // dp[i][j][1] = sum(i~j)
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                dp[i][j][1] = psum[j+1] - psum[i];
            }
        }
        // DP step (over length)
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int j = i+len-1;
                // len([i, j]) == len
                for(int _m = 2; _m <= m; _m++){
                    for(int k = i; k < j; k++){
                        // dp[k+1][j][m-1] == +inf if len([k+1, j]) < m-1
                        if(j-k+1 < _m-1){
                            assert(dp[k+1][j][_m-1] == -1);
                            break;
                        }
                        int val = max(dp[i][k][1], dp[k+1][j][_m-1]);
                        if(dp[i][j][_m] == -1) dp[i][j][_m] = val;
                        else dp[i][j][_m] = min(dp[i][j][_m], val);
                    }
                }
            }
        }
        return dp[0][n-1][m];
    }
};
