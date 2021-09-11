class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // dp[i][j] == the maximmum square ending at (i, j)
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(matrix[0][j]){
                dp[0][j] = 1;
                ans += 1;
            }
        }
        for(int i = 1; i < m; i++){
            if(matrix[i][0]){
                dp[i][0] = 1;
                ans += 1;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0) continue;
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
