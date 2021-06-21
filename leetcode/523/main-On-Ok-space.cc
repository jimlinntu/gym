using Prefix = int;
using Idx = int;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Intuition: working these numbers under modk
        // Maintain an accumulated sum called sum_i
        // For each i, we want to find a subarray ending at i
        // that its sum (we called X = 0 mod k)

        // Suppore during the loop, we record every prefix sum we encounter
        // we want to find a prefix sum that:
        // sum_j + X = sum_i and X = 0
        // That says if we encounter a prefix sum_j = sum_i, we know [j+1, i]'s X == 0

        int n = nums.size();
        int s = 0;
        unordered_map<Prefix, Idx> map;
        // prefix sum: [0, -1]
        map[0] = -1;
        for(int i = 0; i < n; i++){
            s += nums[i];
            s = s % k;
            auto it = map.find(s);
            // sum_j == sum_i found (X = 0)
            // Check whether i - j >= 2
            if(it != map.end()){
                int j = it->second;
                if(i - j >= 2) return true;
                // do nothing
                // note: we will not touch map[s]
                // because saving the more previous j will help us get longer subarray!
            }else{
                map[s] = i; // record its prefix sum position
            }
        }

        return false;
    }
};
