class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> map;
        for(int num: nums){
            map[num]++;
        }
        int n = map.size();
        vector<int> dp(n);
        auto it = map.begin();
        // delete the first number
        dp[0] = map.begin()->first * map.begin()->second;
        for(int i = 1; i < n; i++){
            it++;
            auto prev_it = prev(it);
            if(prev_it->first == it->first-1){
                dp[i] = dp[i-1]; // not delete
                if(i - 2 >= 0)
                    dp[i] = max(dp[i], dp[i-2]+it->first*it->second);
                else
                    dp[i] = max(dp[i], 0+it->first*it->second);
            }else{
                dp[i] = dp[i-1]+it->first*it->second;
            }
        }
        return dp[n-1];
    }
};
