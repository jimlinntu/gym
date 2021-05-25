class Solution {
public:
    int numTrees(int n) {
        // dp[n] == the number of unique BST's if we have n nodes
        // Idea:
        // Each node can become a possible root
        // So we consider all possible roots, and we can derive this recursion
        // dp[n] = dp[0] * dp[n-1] + dp[1] * dp[n-2] ... dp[n-1] * dp[0]
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                // the number of possible structures on the left
                // times the number of possible structures on the right
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};
