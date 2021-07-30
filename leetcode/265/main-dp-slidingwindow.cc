struct E{
    int idx;
    int val;
};

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        // color: a b c
        // 0 1 2 3 4 5
        //           a
        //         b
        //         c
        int n = costs.size();
        if(n == 0) return 0;
        int k = costs[0].size();
        if(k == 0) return INT_MAX;
        vector<vector<int>> dp(n, vector<int>(k));
        for(int c = 0; c < k; c++){
            dp[0][c] = costs[0][c];
        }
        
        // Naive way will take: O(nk^2)
        // dp[i][c] == min({dp[i-1][cc]}) + costs[i][c]
        //             where cc != c
        // c = 0 1 2 3 4 5 6
        //     x
        //       x
        //         x
        deque<E> dq;
        for(int i = 1; i < n; i++){
            // Initially put 1 2 3 4 5 6 ... k-1
            //
            for(int c = 1; c < k; c++){
                // pop things that are >= than the current color
                // maintain a increasing monotonic queue
                while(!dq.empty() and dq.back().val > dp[i-1][c]){
                    dq.pop_back();
                }
                dq.push_back({c, dp[i-1][c]});
            }
            dp[i][0] = dq.front().val + costs[i][0];
            // sliding window minimum
            for(int c = 0; c < k-1; c++){
                // pop those whose val > dp[i-1][c] and older than c
                while(!dq.empty() and dq.back().val > dp[i-1][c]){
                    dq.pop_back();
                }
                // push it back
                dq.push_back({c, dp[i-1][c]});
                // pop outdated
                if(!dq.empty() and dq.front().idx == c+1){
                    dq.pop_front();
                }

                dp[i][c+1] = dq.front().val + costs[i][c+1];
            }
            dq.clear();
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
