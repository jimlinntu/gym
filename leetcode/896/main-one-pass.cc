class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // 0: undetermined
        // 1: increasing
        // 2: decreasing
        int flag = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(flag == 0){
                if(nums[i-1] < nums[i]) flag = 1;
                else if(nums[i-1] > nums[i]) flag = 2;
            }else if(flag == 1){
                // violation
                if(nums[i-1] > nums[i]) return false;
            }else{
                // violation
                if(nums[i-1] < nums[i]) return false;
            }
        }
        return true;
    }
};
