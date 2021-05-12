class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // A decreasing stack
        // stk will contain indices pointing to t
        int n = t.size();
        stack<int> stk;
        vector<int> wait_days(n, 0);
        for(int i = 0; i < n; i++){
            while(!stk.empty() and t[stk.top()] < t[i]){
                wait_days[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return wait_days;
    }
};
