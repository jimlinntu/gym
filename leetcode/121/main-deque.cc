class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // this container will only store strictly increasing sequence
        // when we encounter a value (say, v)
        // we will pop out the values inside this container
        // until v >= the value of the top one of the container
        deque<int> dq;
        int n = prices.size();
        int max_profit = 0;

        for(int i = 0; i < n; i++){
            int p = prices[i];
            while(!dq.empty() && dq.back() >= p){
                dq.pop_back();
            }
            dq.push_back(p);

            max_profit = max(max_profit, dq.back() - dq.front());
        }

        return max_profit;
    }
};
