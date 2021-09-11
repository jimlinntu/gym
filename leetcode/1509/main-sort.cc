class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        // change all to same values
        if(n <= 3) return 0;
        sort(nums.begin(), nums.end());
        // 4 options: 3 front 0 back
        //            2       1
        //            1       2
        //            0       3
        int ans = INT_MAX;
		// NOTE: we can use PQ to reduce this into O(n) time (only store top 4 most and 4 least)
        ans = min(ans, nums[n-1]-nums[3]);
        ans = min(ans, nums[n-2]-nums[2]);
        ans = min(ans, nums[n-3]-nums[1]);
        ans = min(ans, nums[n-4]-nums[0]);
        return ans;
    }
};
