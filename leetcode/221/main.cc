class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int max_width = 0;
        // dp[i][j] is the maximum square area with its down-right corner on (i, j)
        vector<int> dp(n+1, 0);
        for(int i = 0; i < m; i++){
            // Ex.
            // 1 1 1
            // 1 1 1
            // 1 1 1
            //     ^ If this position can span a square with size 3, its
            //       up, up-left, and left position must all can span a square with size 2
            //       so as to form a sqaure with size 3 in this position.
            for(int j = 1, prev = dp[0]; j <= n; j++){
                int old_dp_j = dp[j];
                if(matrix[i][j-1] == '1'){
                    dp[j] = 1 + min({dp[j], dp[j-1], prev});
                }else{
                    dp[j] = 0; // 0 
                }
                prev = old_dp_j;
                max_width = max(max_width, dp[j]);
            }
        }
        return max_width * max_width;
    }
};
