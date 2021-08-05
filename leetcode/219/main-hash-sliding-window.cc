class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Brute force: O(nk): for each position, check [i, i+k]
        unordered_set<int> s;
        int n = nums.size();
        int r = 0;
        for(int i = 0; i < n; i++){
            while(r <= i+k and r < n){
                // add a character
                // if this character is seen before, return true
                if(s.count(nums[r])) return true;
                s.insert(nums[r]);
                r++;
            }
            // [i, r ==i+k]
            
            // remove nums[i]
            s.erase(nums[i]);
        }
        return false;
    }
};
