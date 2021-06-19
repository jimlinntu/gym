struct E{
    int idx;
    int val;
};

class Solution {
public:
    int getMoneyAmount(int n) {
        // O(n^2)
        // dp[1][n] is the answer
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[a][b] == min (i + max(dp[a][i-1], dp[i+1][b]))
        // where a <= i <= b
        // Observe (use proof of contradiction)
        // 1. dp[a][i-1] is a monotonic increasing sequence as i goes larger
        // 2. dp[i+1][b] is a monotonic decreasing sequence as i goes larger
        // Define k == max{i: dp[a][i-1] <= dp[i+1][b]}
        // (NOTE: Ignore a == b because dp[a][a] == 0, we do not care about its k.
        //        For b - a == 2 case, by our definition k does not exist
        //        but you will find that by setting k == a, is safe during our computation.
        //        or you can just handle the base case in advance so b - a >= 3)
        //
        // Observe that we can use k to divide a <= i <= b into two parts
        // (1) a <= i <= k and (2) k < i <= b
        // (1) => max(dp[a][i-1], dp[i+1][b]) == dp[i+1][b]
        // (2) => max(dp[a][i-1], dp[i+1][b]) == dp[a][i-1]
        //
        // Define dp1[a][b] == min (i + max(dp[a][i-1], dp[i+1][b])) where i in (1) --- (i)
        //        dp2[a][b] == min (i + max(dp[a][i-1], dp[i+1][b])) where i in (2) --- (ii)
        // (i)  dp1[a][b] == min (i + dp[i+1][b])) where i in (1)
        // (ii) dp2[a][b] == min (i + dp[a][i-1]) where i in (2)
        //                (choose i == k+1 because it must result the smallest value)
        //                == k + 1 + dp[a][k]
        //
        // There remains two parts to handle:
        // 1) how to compute k in amortized O(1)
        // 2) how to compute dp1[a][b] in amortized O(1)
        //
        // For 1), observe:
        // k == max{i: dp[a][i-1] <= dp[i+1][b]}
        // if a' = a - 1
        // for every i, a <= i <= b, dp[a'][i-1] >= dp[a][i-1] (proof by contradiction)
        // That is: as a goes left, k will only move left or stay! (See the graph in my pdf)
        // initially if a == 2 and b == 4, k == 3,
        // if a'= a-1 = 1, let k' = max{i: dp[a'][i-1] <= dp[i+1][b]}
        // k' <= k
        // Therefore, k' can be computed in amortized O(1) time
        
        // For 2), if we already know k, observe
        // dp1 = min (i + dp[i+1][b])) where a <= i <= k
        //
        // When we move a to the left, say: a' = a - 1 (move left)
        // k' <= k and
        // dp1' = min (i + dp[i+1][b])) where a' <= i <= k'
        //
        // Did you see it?  a <= i <= k ===> a' <= i <= k'
        // And we want to know the minimum
        // That is a "Sliding Window Minimum" problem!
        // Therefore, dp1 can be done in amortized O(1) time
        
        // P.S: You may wonder what we have to fix b and loop over a
        //      Why don't we fixed a and loop over b?
        //      Observe: dp1 = min (i + dp[i+1][b]))
        //      If we fixed a and increment b, our values inside our deque
        //      will be completely different!
        //      So the only way to make it a row-based solution is to
        //      define dp'[b][a] === dp[a][b]
        //      But here I do not want to use dp'[b][a] to blow my mind,
        //      I just stick with a col-based solution here.

        // Handle cases where k does not exist
        // dp[a][a] == 0
        // dp[a][a+1] == min(a + dp[a+1][a+1], a+1 + dp[a][a])
        for(int a = 1; a <= n-1; a++){
            dp[a][a+1] = min(a + dp[a+1][a+1], a+1 + dp[a][a]);
        }
        // Start from b - a >= 3
        for(int b = 3; b <= n; b++){
            // The first [a, b] if of length 3
            // Ex. a == 1, b == 3 ==> k = 2 (the middle)
            // Initially, a = b-2, k = (a+b)/2 = b-1
            deque<E> dq;
            // Push initial k into the dq.
            // Otherwise, we are computing [a, k) rather than [a, k]
            int k = b-1;
            dq.push_back({k, k + dp[k+1][b]});
            for(int a = b-2; a >= 1; a--){
                // k = max{i: dp[a][i-1] <= dp[i+1][b]}
                // Move k to the left (smaller)
                // if dp[a][k-1] <= dp[k+1][b] is NOT satisfied
                while(dp[a][k-1] > dp[k+1][b]){
                    k--;
                }
                // dp1 = min (i + dp[i+1][b])) where a <= i <= k
                //
                // Remove out-of-window elements (remove idx > k)
                // because we cannot use these numbers to compute minimum
                while(!dq.empty() and dq.front().idx > k){
                    dq.pop_front();
                }
                // New window: a' <= i <= k'
                int val = a + dp[a+1][b];
                // Put (a, a + dp[a+1][b]) in the back of the deque
                while(!dq.empty() and dq.back().val >= val){
                    // You are useless because
                    // a's index is newer and have value less than yours
                    dq.pop_back();
                }
                dq.push_back({a, val});

                int dp1 = dq.front().val;
                int dp2 = k + 1 + dp[a][k];
                dp[a][b] = min(dp1, dp2);
            }
        }
        return dp[1][n];
    }
};
