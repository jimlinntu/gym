class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        // Normalize each number to [0, k)
        for(int i = 0; i < n; i++){
            int num = nums[i];
            while(num < 0) num += k;
            nums[i] = num % k;
        }
        int prefix = 0;
        // map[prefix] = count
        unordered_map<int, int> map;
        // sum(0~-1)
        map[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            // (sum(0~i) - sum(0~j)) % k == 0
            // sum(0~j)% k == sum(0~i)%k
            prefix = (prefix + nums[i]) % k;
            if(map.count(prefix)){
                ans += map[prefix];
            }

            map[prefix]++; // add this sum(0~j)
        }
        return ans;
    }
};
