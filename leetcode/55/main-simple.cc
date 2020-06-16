class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return true;
        int max_can_reach = 0;
        for(int i = 0; i <= max_can_reach; i++){
            max_can_reach =                 (max_can_reach < i+nums[i])?(i+nums[i]):(max_can_reach);
            if(max_can_reach >= n-1) return true;
        }
        return false;
    }
};
