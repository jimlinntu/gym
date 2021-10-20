struct Bucket{
    bool has_num = false;
    int mn = INT_MAX, mx = INT_MIN;
    Bucket(){
    }
    void put(int v){
        has_num = true;
        mn = min(mn, v);
        mx = max(mx, v);
    }
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // n-1 slots
        // [min, max]
        // (max-min)/(n-1) is the maximum gap
        // Ex. [0, 7], {0, 3.5, 7}
        int n = nums.size();
        if(n < 2) return 0;
        int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        if(n == 2) return mx - mn;
        if(mx - mn == 0) return 0;
        // NOTE: if mx-mn > n-1 => min_max_gap >= 2
        // ceil((mx-mn)/(n-1))
        int min_max_gap = (mx-mn+(n-2))/(n-1);
        // set it to be smaller than mininimum maximum gap!
        int w = max(min_max_gap-1, 1);
        assert(w != 0);
        // Divide the value space
        int num_buckets = (mx-mn+1 + w) / (w+1);
        // Because [0, w] will not contain even the minimum maximum gap!
        vector<Bucket> buckets(num_buckets);
        for(int num: nums){
            // Get the bucket index
            int bidx = (num-mn) / (w+1);
            // Put it into the bucket
            buckets[bidx].put(num);
        }
        // Loop over buckets
        int ans = INT_MIN;
        Bucket prev;
        for(int i = 0; i < num_buckets; i++){
            if(!buckets[i].has_num) continue;
            if(prev.has_num){
                ans = max(ans, buckets[i].mn - prev.mx);
            }
            prev = buckets[i];
        }
        return ans;
    }
};
