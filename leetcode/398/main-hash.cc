class Solution {
public:
    unordered_map<int, vector<int>> map;
    default_random_engine g;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto &v = map[target];
        if(v.size() == 0) return -1;
        uniform_int_distribution d(0, (int)v.size()-1);
        return v[d(g)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
