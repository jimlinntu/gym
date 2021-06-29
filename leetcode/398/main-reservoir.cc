class Solution {
public:
    vector<int> a;
    default_random_engine g;
    Solution(vector<int>& nums) {
        a = nums;
    }

    int pick(int target) {
        int pick_idx = -1;
        int n_target = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == target){
                // So far we have seen [0, n_target] numbers
                // This if statement basically means:
                // whether we want to choose this number as our result
                if(uniform_int_distribution<int>(0, n_target)(g) == n_target){
                    pick_idx = i;
                }
                n_target++;
            }
        }
        return pick_idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
