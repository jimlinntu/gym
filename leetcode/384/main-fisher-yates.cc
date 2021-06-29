class Solution {
public:
    vector<int> a;
    default_random_engine g;
    Solution(vector<int>& nums) {
        a = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // See the proof here:
        // https://nishmathcs.wordpress.com/2017/10/05/fisher-yates-proof/
        int n = a.size();
        if(n == 0) return {};
        vector<int> shuffled = a;
        for(int i = 0; i < n-1; i++){
            int j = uniform_int_distribution<int>(i, n-1)(g);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
