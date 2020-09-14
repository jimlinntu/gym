class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        // dp[i] == match word2 [0, i)
        vector<int> dp(n+1);
        for(int i = 0; i <= n; i++){
            dp[i] = i; // word1: [0, 0) ->(i insertions) word2: [0, i)
        }
        /*      (prev)
            |dp(i-1, j-1)|   |dp(i-1, j)|
            |dp(i, j-1)  |   |dp(i, j)  |
        */
        for(int i = 1; i <= m; i++){
            // word1: [0, i) matching word2: [0, j)
            int prev = dp[0]; // backup dp(0, 0)
            dp[0] = i; // word2: [0, i) ->(i deletes) word2: [0, 0)
            for(int j = 1; j <= n; j++){
                // Recursion:
                // dp(i, j) = dp(i-1, j-1)
                if(word1[i-1] == word2[j-1]){
                    // put prev into dp[j]
                    // and then backup dp[j] into prev
                    swap(dp[j], prev);
                }else{
                    int de, ins, repl;
                    // delete: dp(i-1, j) + 1
                    de = dp[j] + 1;
                    // insert: dp(i, j-1) + 1
                    ins = dp[j-1] + 1;
                    // replace: dp(i-1, j-1) + 1
                    repl = prev + 1;
                    // (backup dp(i-1, j-1))
                    prev = dp[j];
                    // dp step
                    dp[j] = min({de, ins, repl});
                }
            }
        }
        return dp[n];
    }
};
