class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        for(int num: nums) s += num;
        int n = nums.size();
        int left = 0;
        for(int i = 0; i < n; i++){
            // left == sum from nums[0]~nums[i-1]
            // right == sum from num[i+1]~nums[n-1]
            if(left == s - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};
