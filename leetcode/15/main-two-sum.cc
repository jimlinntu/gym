class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void two_sum(vector<int> &nums, int i, int target){
        int l = i, r = n-1;
        while(l < r){
            int s = nums[l] + nums[r];
            if(s == target){
                // Ex. -6 1 1 1 5 5 5 5 5
                //      * ^             ^ <----- this should be considered
                //          ^         ^   <----- this should not be considered
                // NOTE: if after l++ and r--, one value differs,
                //       the next loop will not fall into this section!
                if((l == i or nums[l-1] != nums[l]) and
                   (r == n-1 or nums[r] != nums[r+1])){
                    ans.push_back({nums[i-1], nums[l], nums[r]});
                }
                // Because nums[l] + nums[r] == target
                // nums[l+1] + nums[r] >= target
                // and nums[l] + nums[r-1] <= target
                // if we only move l or r, we will get duplicate triplets
                // That's why here I move two pointers inward
                l++, r--;
            }else if(s > target){
                r--;
            }else{
                l++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        if(n < 3) return {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            // avoid duplicates
            if(i > 0 and nums[i-1] == nums[i]) continue;
            two_sum(nums, i+1, -nums[i]);
        }
        return ans;
    }
};
