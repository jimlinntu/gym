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
        // dp[i][j][m] == min(dp[i][k][1] + dp[k+1][j][m-1])
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
        for(int len = 2; len <= n; len++){
            for(int i = 0, j; i <= n-len; i++){
                j = i + len - 1;
                // [i, j] with len
                for(int m = 2; m <= K; m++){
                    // if len < m: impossible to form m piles
                    // if (len - m) % (K-1) != 0: impossible to form m piles
                    if(len < m or (len - m) % (K-1) != 0) continue; 
                    for(int k = i; k < j; k++){
                        int left_len = k - i + 1;
                        int right_len = len - left_len;
                        // impossible to form 1 piles
                        if((left_len - 1) % (K-1) != 0){
                            assert(dp[i][k][1] == -1);
                            continue;
                        }
                        // impossible to form m-1 piles
                        if(right_len < m-1 or (right_len - (m-1)) % (K-1) != 0){
                            assert(dp[k+1][j][m-1] == -1);
                            continue;
                        }
                        if(dp[i][j][m] == -1) dp[i][j][m] = dp[i][k][1] + dp[k+1][j][m-1];
                        else dp[i][j][m] = min(dp[i][j][m], dp[i][k][1] + dp[k+1][j][m-1]);
                    }
                }
                // Compute dp[i][j][1]
                if((len - 1) % (K-1) == 0){
                    assert(dp[i][j][K] != -1);
                    dp[i][j][1] = dp[i][j][K] + psum[j+1] - psum[i];
                }
            }
        }
        return dp[0][n-1][1];
    }
};
