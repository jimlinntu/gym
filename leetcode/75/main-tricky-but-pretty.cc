class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;
        int place_0_idx = 0, place_2_idx = n-1;
        int moving_idx = 0;
        while(moving_idx <= place_2_idx){
            // During the process:
            // [0, place_0_idx) will be all 0
            // (place_2_idx, n) will be all 2
            // This is why this algorithm is correct
            
            // Tricky cases:
            // 1. [2, 0, 1]
            int num = nums[moving_idx];
            if(num == 0){
                // [2 ..... 0 ..... 1] this kind of case will not happen!
                //  ^       ^       ^
                //  0idx            2idx
                // Because when we encounter the first 2, it will be moved to the back already
                assert(nums[place_0_idx] != 2); // 2 must be moved to the back first
                swap(nums[place_0_idx++], nums[moving_idx++]);
            }else if(num == 2){
                // Whenever we encounter a 2, put it at place_2_idx
                swap(nums[place_2_idx--], nums[moving_idx]);
            }else moving_idx++;
        }
    }
};
