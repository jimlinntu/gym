class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst) return 0;
        // dp[k][i] == the distance from src to i within k steps
        vector<vector<int>> dp(K+2, vector<int>(101, INT_MAX));
        // dp[k][src] == 0
        for(int k = 0; k <= K+1; k++){
            dp[k][src] = 0;
        }

        // Bellman Ford algorithm
        for(int k = 1; k <= K+1; k++){
            for(int i = 0; i < flights.size(); i++){
                int s = flights[i][0];
                int d = flights[i][1];
                int w = flights[i][2];
                // if from src to s is still infinity, skip it
                if(dp[k-1][s] != INT_MAX)
                    // Propagate the information out
                    dp[k][d] = min(dp[k][d], dp[k-1][s] + w);
            }
        }
        return (dp[K+1][dst] == INT_MAX) ? (-1):(dp[K+1][dst]);
    }
};
