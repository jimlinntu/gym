using LL = long long int;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        // 0: [INT_MIN, INT_MIN+t]
        // 1: [INT_MIN+t+1, INT_MIN+2t+1]
        // ...
        unordered_map<LL, int> bucket;
        for(int i = 0; i < n; i++){
            // 
            if(i-k-1 >= 0){
                // remove that number
                LL idx = ((LL)nums[i-k-1]-INT_MIN)/((LL)t+1);
                bucket.erase(idx);
            }
            LL bidx = ((LL)nums[i]-INT_MIN)/((LL)t+1);

            if(bucket.count(bidx)) return true;
            // check nearby buckets (bidx-1, bidx+1)
            if(bucket.count(bidx-1) and (LL)nums[i]-bucket[bidx-1] <= t) return true;
            if(bucket.count(bidx+1) and (LL)bucket[bidx+1]-nums[i] <= t) return true;
            // put nums[i] in the bucket
            bucket[bidx] = nums[i];
        }
        return false;
    }
};
