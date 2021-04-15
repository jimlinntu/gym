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
        // dp[i][j][m] == the min cost to merge stones[i~j] into m piles
        // Initially, mark all elements as -1 (impossible to form m piles for [i, j])
        vector<vector<vector<int>>> dp(n,
                                       vector<vector<int>>(n,
                                       vector<int>(K+1, -1)));
        // In general:
        // dp[i][j][m] == min(dp[i][k][1] + dp[k+1][j][m-1] + sum(i~j))
        // Note: i~k and k+1~j will not interfere other sides until the last move
        //       You can also see that the merging of i~k and k+1~j is the last move
        //       Pretty much similar to Burst Balloons problem
        // Special cases:
        // 1. dp[i][i][1] = 0
        // 2. dp[i][j][1] = dp[i][j][K] + sum(i~j) (First form K piles and then merge it)
        //    (Comment: Too intricate.......)
        for(int i = 0; i < n; i++){
            dp[i][i][1] = 0; // no need to merge anymore
        }
        // DP over length (from len 2 to len n)
        // Idea: because we will always need to know the smaller len
        //       to compute the larger len, it is reasonable to DP over smaller len
        for(int len = 2; len <= n; len++){
            // [i, j] with len (i.e. j - i + 1 == len)
            for(int i = 0; i <= n-len; i++){
                int j = i + len - 1;
                int sum = psum[j+1] - psum[i];
                // dp[i][j][m] == min(dp[i][k][1] + dp[k+1][j][m-1] + sum(i~j))
                for(int m = 2; m <= K; m++){
                    for(int k = i; k < j; k++){
                        //    [i, k] cannot form 1 pile
                        // or [k+1, j] cannot form 1 pile
                        // we will skip it
                        if(dp[i][k][1] == -1 or dp[k+1][j][m-1] == -1) continue;
                        
                        if(dp[i][j][m] == -1){
                            dp[i][j][m] = dp[i][k][1] + dp[k+1][j][m-1];
                        }else{
                            dp[i][j][m] = min(dp[i][j][m],
                                dp[i][k][1] + dp[k+1][j][m-1]);
                        }                        
                    }
                }
                // dp[i][j][1] == form K piles and merge it
                //             == dp[i][j][K] + sum(i~j)
                if(dp[i][j][K] != -1) dp[i][j][1] = dp[i][j][K] + sum;
            }
        }
        
        return dp[0][n-1][1];
    }
};


