class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if(n == 0) return -1;
        // n == 1 + (K - 1) q
        if((n-1) % (K-1) != 0) return -1;
        // prefix sum
        vector<int> psum(n+1);
        psum[0] = 0;
        for(int i = 0; i < n; i++){
            psum[i+1] = psum[i] + stones[i];
        }
        // dp[i][j] == the minimum cost to merge [i, j] as compact as possible
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // Base cases:
        // dp[i][i] = 0
        for(int i = 0; i < n; i++){
            dp[i][i] = 0;
        }
        // dp[i][j] = min (dp[i][k] + dp[k+1][j]) + sum(i~j) if (j-i) % (K-1) == 0 else 0
        // Because if (len([i, j])-1) % (K-1) == 0, it means [i, j] can be merged into 1 pile
        // , we will need to add the cost to merge this [i, j]

        // DP over length
        for(int len = 2; len <= n; len++){
            for(int i = 0, j; i <= n-len; i++){
                j = i + len - 1;
                // Consider case K = 3, dp[0][3]
                // if we take dp[0][3]
                // consider k = 1
                // dp[0][1] is of length 2
                // dp[2][3] is of length 2
                // ==> it requires 2 merging operations.
                // But in our dp computation, we only consider at most 1 merging operation!!!!
                // That's why we CANNOT consider k = 1 in this case
                // Because we should always ensure dp[i][k] and dp[k+1][j] can be merged
                // by exactly 1 operation!
                for(int k = i; k < j; k += K-1){
                    assert(dp[i][k] != -1 and dp[k+1][j] != -1);
                    int val = dp[i][k] + dp[k+1][j];
                    if(dp[i][j] == -1) dp[i][j] = val;
                    else dp[i][j] = min(dp[i][j], val);
                }
                // If this range can be merged into 1 pile
                if((len-1) % (K-1) == 0) dp[i][j] += psum[j+1] - psum[i];
            }
        }
        return dp[0][n-1];
    }
};
