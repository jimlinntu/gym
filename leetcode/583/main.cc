class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> dp(n+1);
        // Init: dp(0, j) == word1: [0, 0), word2: [0, j) will take j deletions
        for(int j = 0; j <= n; j++){
            dp[j] = j;
        }
        // Compute: dp(i, j): word1: [0, i), word2: [0, j)
        // if word1[i-1] == word2[j-1]: dp(i, j) == dp(i-1, j-1)
        // else: dp(i, j) == min(dp(i-1, j)(del word1[i-1]), dp(i, j-1)(del word2[j-1])) + 1
        int prev;
        for(int i = 1; i <= m; i++){
            prev = dp[0]; // dp(i-1, j-1)
            dp[0] = i;
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    swap(dp[j], prev); 
                }else{
                    prev = dp[j];
                    dp[j] = min(dp[j-1], dp[j]) + 1;
                }
            }
        }
        return dp[n];
    }
};
