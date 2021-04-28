class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int allsum = 0;
        for(int num: nums) allsum += num;
        int cursum = 0;
        for(int i = 0; i < n; i++){
            if(cursum == allsum - nums[i] - cursum) return i;
            cursum += nums[i];
        }
        return -1;
    }
};
