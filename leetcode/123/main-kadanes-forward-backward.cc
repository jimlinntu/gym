class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // forward[i] == the max_profit within [0, i]
        // backward[i] == the max_profit within [n-i-1, n-1]
        vector<int> forward(n, 0);
        vector<int> backward(n, 0);
        // forward Kadanes
        int forward_backward_max_profit = 0;
        int max_profit = 0;
        int imax = 0; // the max profit can be achieved when ending by the index i
        for(int i = 1; i < n; i++){
            int diff = prices[i] - prices[i-1];
            // 1. zero length subarray (of diffs)
            // 2. consider imax
            imax = max(0, imax + diff);
            max_profit = max(max_profit, imax);
            forward[i] = max_profit;
        }
        forward_backward_max_profit = max(forward_backward_max_profit, max_profit);
        // backward Kadanes
        max_profit = 0;
        imax = 0; // the max profit can be achieved when ending by the index i (backwardly)
        for(int i = 1; i < n; i++){
            int diff = prices[n-i] - prices[n-i-1];
            // 1. zero length subarray
            // 2. consider imax
            imax = max(0, imax + diff);
            max_profit = max(max_profit, imax);
            backward[i] = max_profit;
        }


        // Combine forward and backward information
        for(int i = 0; i < n-1; i++){
            forward_backward_max_profit = \
                    max(forward_backward_max_profit, forward[i]+backward[n-i-1]);
        }
        return forward_backward_max_profit;
    }
};
