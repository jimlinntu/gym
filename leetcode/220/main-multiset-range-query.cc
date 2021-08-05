using LL = long long int;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // |nums[i] - nums[j]| <= t
        // => -t <= nums[i] - nums[j] <= t
        // => -t + nums[j] <= nums[i] and nums[i] <= t + nums[j]
        int n = nums.size();
        multiset<LL> s;
        // O(n log k)
        for(int i = 0; i < n; i++){
            if(i-k-1 >= 0) s.erase(s.find(nums[i-k-1]));

            // at least a number >= -t+nums[i]
            // O(log k) query
            auto lit = s.lower_bound((LL)-t+(LL)nums[i]);
            // at least a number <= t+nums[i]
            // NOTE: this is the first iterator > t+nums[i]
            // O(log k) query
            auto uit = s.upper_bound((LL)t+(LL)nums[i]);
            
            // O(1) because we will at most step 1
            for(auto it = lit; it != uit; it++){
                // there exists [-t+nums[i], t+nums[i]]
                return true;
            }
            
            s.insert(nums[i]);
        }
        return false;
    }
};
