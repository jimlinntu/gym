ass Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int n = nums.size();
        // Greedy pairing
        // See my pdf for more information
        for(int i = 0; i < n/2; i++){
            ans = max(ans, nums[i]+nums[n-1-i]);
        }
        return ans;
    }
};
