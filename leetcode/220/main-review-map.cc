using LL = long long int;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // map[num] == count within this window: [r-k, r]
        map<LL, int> map;
        int n = nums.size();
        // Overall: O(n log n)
        for(int r = 0; r < n; r++){
            // NOTE: only check (i < j) pairs are sufficient
            // remove nums[r-k-1] or allow only [r-k, r]
            if(r-k-1 >= 0){
                if(--map[nums[r-k-1]] == 0) map.erase(nums[r-k-1]);
            }
            // find if there is a number within
            //    |nums[i]-nums[j]| <= t
            // -t+nums[j] <= nums[i] <= t+nums[j]
            // Query the range
            // O(log n)
            auto lb = map.lower_bound(-(LL)t+nums[r]);
            auto ub = map.upper_bound((LL)t+nums[r]);
            // [lb, ub)
            // walk one step
            for(auto it = lb; it != ub; it++){
                return true;
            }
            // add this nums[r]
            map[nums[r]]++;
        }
        return false;
    }
};
