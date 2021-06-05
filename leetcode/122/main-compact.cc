class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Peak Valley
        int n = prices.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            // Buy at i and sell at i+1
            if(prices[i+1] - prices[i] > 0) ans += prices[i+1] - prices[i];
        }

        return ans;
    }
};
