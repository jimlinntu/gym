class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1) return 0;
        int score = nums[n-1]-nums[0];
        // i is the split point
        // NOTE: n-1 can be a split point, but it will produce the same answer
        //       as nums[n-1]-nums[0], so we can safely ignore
        for(int i = 0; i < n-1; i++){
            // Only check the last one when we have duplicates
            if(nums[i] == nums[i+1]) continue;
            // Everything in front of nums[0]~nums[i] will add +2k
            assert(nums[i+1] > nums[i]);
            int min_ = min(nums[0]+2*k, nums[i+1]);
            int max_ = max(nums[i]+2*k, nums[n-1]);

            score = min(score, max_-min_);
        }

        return score;
    }
};
