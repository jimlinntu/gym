class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        // Complexity: O(n^2)
        // DP over rows
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1] + triangle[i][i];
            for(int j = i-1; j > 0; j--){
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] = dp[0] + triangle[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
