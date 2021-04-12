class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        if(n == 0) return 0;
        // dp[i] == the minimum cost starting with days[i] to days[n-1]
        vector<int> dp(n+1);
        dp[n-1] = *min_element(costs.begin(), costs.end());
        dp[n] = 0; // dummy one

        int next_7 = n;
        int next_30 = n;
        // time complexity: O(3 * n)
        for(int i = n-2; i >= 0; i--){
            // Compute:
            // dp[i] == min(costs[0] + dp[i+1],
            //              costs[1] + dp[first j s.t days[j] - days[i] >= 7],
            //              costs[2] + dp[first j s.t days[j] - days[i] >= 30])
            dp[i] = costs[0] + dp[i+1];
            // move next_7 as left as possible
            // s.t. it is the first j s.t. days[j] - days[i] >= 7
            while(next_7-1 >= 0 and days[next_7-1] - days[i] >= 7){
                next_7--;
            }
            while(next_30-1 >= 0 and days[next_30-1] - days[i] >= 30){
                next_30--;
            }
            dp[i] = min(dp[i], costs[1] + dp[next_7]);
            dp[i] = min(dp[i], costs[2] + dp[next_30]);
        }

        // dp[0]: starting from days[0]
        return dp[0];
    }
};
