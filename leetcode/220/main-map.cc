using LL = long long int;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // |nums[i] - nums[j]| <= t
        // => -t <= nums[i] - nums[j] <= t
        // => -t + nums[j] <= nums[i] and nums[i] <= t + nums[j]
        int n = nums.size();
        map<LL, int> s;
        // O(n log k)
        for(int i = 0; i < n; i++){
            // remove out of window
            if(i-k-1 >= 0){
                if(--s[nums[i-k-1]] == 0)
                    s.erase(nums[i-k-1]);
            }
            // find the first one >= -t+nums[i]
            auto lit = s.lower_bound((LL)-t+(LL)nums[i]);
            // find the first one > t+nums[i]
            auto uit = s.upper_bound((LL)t +(LL)nums[i]);
            
            for(auto it = lit; it != uit; it++){
                // hit a nums[j] satisfy:
                // -t + nums[i] <= nums[j] <= t+nums[i]
                return true;
            }
            s[nums[i]]++;
        }
        return false;
    }
};
