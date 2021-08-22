class Solution {
public:
    vector<int> a;
    default_random_engine g;
    Solution(vector<int>& nums) {
        a = nums;
    }
    // https://www.geeksforgeeks.org/reservoir-sampling/
    int pick(int target) {
        int n = a.size();
        int select = -1;
        int len = 0;
        for(int i = 0; i < n; i++){
            int num = a[i];
            if(num != target) continue;
            // Reservoir sampling (with reservoir size == 1)
            
            if(select == -1) select = i;
            else{
                uniform_int_distribution<int> dist(0, len);
                int r = dist(g);
                // if that sample index is in the reservoir, replace
                // that index with this position
                if(r == 0) select = i;
                // else: throw away
            }
            len++;
        }
        return select;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
