using Prefix = int;
using Idx = int;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<Prefix, Idx> map;
        // prefix == 0 and idx == -1
        int s = 0;
        int max_len = 0;
        map[0] = -1;
        for(int i = 0; i < n; i++){
            s += nums[i];
            // Search if there is a prefix sum == s-k
            // so that a subarray will be k (because s - (s-k) == k)
            auto it = map.find(s-k);
            if(it != map.end()){
                max_len = max(max_len, i - it->second);
            }

            // If there is already s in the prefix sum hash table, we do not update it
            // because using the leftmost index will help us get the maximum subarray length!
            if(map.find(s) == map.end()) map[s] = i;
        }
        return max_len;
    }
};
