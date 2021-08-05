class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            // delete the number at i-k-1 outside of this window
            if(i-k-1 >= 0) s.erase(nums[i-k-1]);
            // s now stores the value within [i-k, i-1]
            if(s.count(nums[i])) return true;
            // add the new number
            s.insert(nums[i]);
        }
        return false;
    }
};
