using LL = long long int;

class Solution {
public:
    LL get_bucket_id(int v, int t){
        static int m = numeric_limits<int>::min();
        return ((LL)v-(LL)m) / ((LL)t+1LL);
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // buckets[bidx] == that number inside `bidx` bucket
        // NOTE: a bucket cannot contain 2 numbers
        //       because once it contains 2 numbers, we will return
        unordered_map<LL, int> bucket;
        // buckets will like: [0, t], [t+1, 2t+1]
        // however, the above buckets assume the value space is [0, +inf],
        // nums[i] can be negative.
        // so we can just parition the value space starting from
        // [INT_MIN, INT_MIN+t] ...
        int n = nums.size();
        for(int i = 0; i < n; i++){
            // remove the outdated number
            if(i-k-1 >= 0) bucket.erase(get_bucket_id(nums[i-k-1], t));
            
            LL bidx = get_bucket_id(nums[i], t);
            // check the previous bucket
            //     |nums[i]-nums[j]| <= t
            // ==> -t+nums[i] <= nums[j] <= t+nums[i]
            if(bucket.count(bidx)) return true;
            if(bucket.count(bidx-1) and bucket[bidx-1] >= -(LL)t+nums[i]) return true;
            if(bucket.count(bidx+1) and bucket[bidx+1] <= (LL)t+nums[i]) return true;

            // put this number at this bucket
            bucket[bidx] = nums[i];
        }

        return false;
    }
};
