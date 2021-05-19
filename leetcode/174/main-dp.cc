class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // dp[i][j] == the largest valley among all paths from (i, j) to the goal
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m-1][n-1] = dungeon[m-1][n-1];
        // Base cases:
        for(int i = n-2; i >= 0; i--){
            dp[m-1][i] = min(dungeon[m-1][i],
                             dungeon[m-1][i] + dp[m-1][i+1]);
        }
        for(int i = m-2; i >= 0; i--){
            dp[i][n-1] = min(dungeon[i][n-1],
                             dungeon[i][n-1] + dp[i+1][n-1]);
        }
        // DP step:
        // dp[i][j] == min(dungeon[i][j],
        //                 dungeon[i][j]+max(dp[i+1][j], dp[i][j+1]));
        // The valley can happend at (i, j) or
        // either among the paths on the right or down
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
               dp[i][j] = min(dungeon[i][j],
                              dungeon[i][j] + max(dp[i+1][j], dp[i][j+1]));
            }
        }
        if(dp[0][0] >= 0) return 1;
        else return -dp[0][0]+1;
    }
};
