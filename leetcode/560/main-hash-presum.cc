class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum_frequency;
        // Ex. [1, 2, 3] and k == 1
        presum_frequency[0] = 1;
        int n = nums.size();
        int cur_sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            // Compute the number of whose sum equals to k
            // that ends at i
            // (i.e. if there exist j s.t. sum([j, i]) == k)
            cur_sum += nums[i];
            auto it = presum_frequency.find(cur_sum - k);
            if(it != presum_frequency.end()){
                // there exist a sum([0, j < i]) + k == sum([0, i])
                int freq = it->second;
                ans += freq;
            }
            presum_frequency[cur_sum]++;
        }
        return ans;
    }
};
