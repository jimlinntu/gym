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
        // Handle k == 1 because later we want mini, secondmini all have values
        if(k == 1){
            if(n == 1) return costs[0][0];
            // no way to paint using one color to paint multiple houses
            return INT_MAX;
        }
        vector<vector<int>> dp(n, vector<int>(k));

        int mini = -1, secondmini = -1;
        int cur_mini, cur_secondmini;
        for(int c = 0; c < k; c++){
            dp[0][c] = costs[0][c];

            if(mini == -1) mini = c;
            else if(dp[0][c] < dp[0][mini]){
                secondmini = mini; // pass mini to second mini
                mini = c; // minimum index
            }else if(secondmini == -1) secondmini = c;
            else if(dp[0][c] < dp[0][secondmini]){
                secondmini = c;
            }
        }
        // Naive way will take: O(nk^2)
        // dp[i][c] == min({dp[i-1][cc]}) + costs[i][c]
        //             where cc != c
        // c = 0 1 2 3 4 5 6
        //       *     %    
        //                   <-- row i
        // Let assume * is the minimum, and % is the second minimum
        // we will find that only dp[i][1] cannot use dp[i-1][1],
        // other cells in row i can use *
        // So we just need to use an additional variable to store % as the second minimum
        
        for(int i = 1; i < n; i++){
            cur_mini = -1, cur_secondmini = -1;
            for(int c = 0; c < k; c++){
                if(c != mini) dp[i][c] = dp[i-1][mini] + costs[i][c];
                else{
                    // use the second mini
                    dp[i][c] = dp[i-1][secondmini] + costs[i][c];
                }
                
                if(cur_mini == -1) cur_mini = c;
                else if(dp[i][c] < dp[i][cur_mini]){
                    cur_secondmini = cur_mini;
                    cur_mini = c;
                }else if(cur_secondmini == -1) cur_secondmini = c;
                else if(dp[i][c] < dp[i][cur_secondmini]){
                    cur_secondmini = c;
                }
            }
            // pass to the previous row's minimum and second mininimum
            mini = cur_mini;
            secondmini = cur_secondmini;
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
