class Solution {
public:
    int kadanes(vector<int> &prices, int start, int end){
        int max_profit = 0;
        int imax = 0; // the max profit can be achieved up to index i
        for(int i = start+1; i < end; i++){
            int diff = prices[i] - prices[i-1];
            // 1. Zero length: buy at i, sell at i
            // 2. imax + diff
            imax = max(0, imax + diff);
            max_profit = max(max_profit, imax);
        }
        return max_profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = kadanes(prices, 0, n);
        for(int i = 0; i < n; i++){
            max_profit = max(max_profit, kadanes(prices, 0, i) + kadanes(prices, i, n));
        }
        return max_profit;
    }
};
