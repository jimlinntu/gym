class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int imax = max_sum; // the maximum sum up to the index i
        int n = nums.size();
        for(int i = 1; i < n; i++){
            // We have two choices:
            // 1. ignore the maximum sum up to i-1
            // 2. consider the maximum sum up to i plus nums[i]
            imax = max(nums[i], nums[i] + imax);
            max_sum = max(max_sum, imax);
        }
        return max_sum;
    }
};
