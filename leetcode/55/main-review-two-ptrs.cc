class Solution {
public:
    bool canJump(vector<int>& nums) {
        // two pointers
        int n = nums.size();
        int r = 0;
        for(int i = 0; i < n; i++){
            if(i > r) return false;
            r = max(r, i + nums[i]);
        }
        return true;
    }
};
