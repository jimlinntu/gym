class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxdp(n), mindp(n);
        int ans = mindp[0] = maxdp[0] = nums[0];
        for(int i = 1; i < n; i++){
            maxdp[i] = max({mindp[i-1] * nums[i],
                            maxdp[i-1] * nums[i],
                            nums[i]});
            mindp[i] = min({mindp[i-1] * nums[i],
                            maxdp[i-1] * nums[i],
                            nums[i]});
            ans = max(ans, maxdp[i]);
        }
        return ans;
    }
};
