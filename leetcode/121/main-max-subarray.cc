class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_price = prices[0];
        // I do not buy anything you will not lose money
        int max_profit = 0;
        int n = prices.size();
        // imax will record the max profit can be achieved up to the index i
        int imax = 0;
        for(int i = 1; i < n; i++){
            int diff = prices[i] - prev_price;
            // We have two choices:
            // 1. buy this stock at i and sell it at i (diff == 0) (Allow zero length subarray!)
            // 2. because the max profit can be achieved up to time i-1 is imax
            //    imax + diff (which means sell it at i) can be a possible candidate
            imax = max(0, imax + diff);
            max_profit = max(max_profit, imax);

            prev_price = prices[i];
        }
        return max_profit;
    }
};
