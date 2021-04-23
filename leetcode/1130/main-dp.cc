class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if(n < 2) return -1;
        // maxTable[i][j] == max(arr[i~j])
        vector<vector<int>> maxTable(n, vector<int>(n));
        // dp[i][j] == the minimum sum arr[i~j] can achieve
        // == min k (maxTable[i][k] * maxTable[k+1][j] +
        //           dp[i][k] + dp[k+1][j])
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            maxTable[i][i] = arr[i];
            for(int j = i+1; j < n; j++){
                maxTable[i][j] = max(maxTable[i][j-1], arr[j]);
            }
        }
        // DP over length
        // Note: We assume dp[i][i+1] == 0 here.
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int j = i + len - 1;
                dp[i][j] = numeric_limits<int>::max();
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j],
                       maxTable[i][k]*maxTable[k+1][j]+
                       dp[i][k] + dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
