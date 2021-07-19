struct E{
    int mx;
    int mn;
    E(): mx(INT_MIN), mn(INT_MAX){
    }
    void put(int num){
        mx = max(mx, num);
        mn = min(mn, num);
    }
    bool exists(){
        return mx != INT_MIN; // contain at least one number
    }
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int mx = INT_MIN, mn = INT_MAX;
        for(int num: nums){
            mx = max(mx, num);
            mn = min(mn, num);
        }
        if(n == 2) return mx - mn;
        if(mx - mn == 0) return 0;
        int t = (mx-mn)/(n-1) + ((mx-mn)%(n-1) != 0);
        // buckets[i]: stores number in [min+t*i, min+t*(i+1))
        // NOTE: because there are (mx-mn+1) discrete integers
        //       and each bucket can store at most t integers (maximum gap t-1)
        //       There will be ceil((mx-mn+1) / t) buckets
        int bnum = (mx-mn+1) / t + ((mx-mn+1) % t != 0);
        vector<E> buckets(bnum);
        // Put numbers into buckets
        for(int num: nums){
            // compute the bucket it will be placed
            int bidx = (num - mn) / t;
            buckets[bidx].put(num);
        }
        // Compute the maximum gap from each the gap of each successive buckets
        int ans = 0;
        int prev_max = INT_MIN;
        for(int i = 0; i < buckets.size(); i++){
            if(!buckets[i].exists()) continue;
            if(prev_max != INT_MIN) ans = max(ans, buckets[i].mn - prev_max);
            prev_max = buckets[i].mx;
        }
        return ans;
    }
};
