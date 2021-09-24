class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        // dp[i][j] == from [0,i) stations, the farest we can go by stoping j times
        // NOTE: i >= j, that means only the lower triangle is valid
        // dp[i][j] = to refuel at i or not
        //          = max(dp[i-1][j-1]+fuel_i if dp[i-1][j-1] >= x_i,
        //                dp[i-1][j] if dp[i-1][j] >= x_i)
        //            Otherwise, dp[i][j] = -1
        if(startFuel >= target) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        dp[0][0] = startFuel;
        for(int i = 1; i <= n; i++){
            if(stations[i-1][0] <= startFuel)
                dp[i][0] = startFuel; // using no fuel stops
        }
        for(int j = 1; j <= n; j++){
            // at least i stops
            int max_dist = -1;
            for(int i = j; i <= n; i++){
                int x = stations[i-1][0];
                int fuel = stations[i-1][1];
                if(x <= dp[i-1][j-1]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+fuel);
                }
                if(i-1 >= j and x <= dp[i-1][j]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
                max_dist = max(max_dist, dp[i][j]);
            }
            if(max_dist >= target) return j;
        }
        return -1;
    }
};
