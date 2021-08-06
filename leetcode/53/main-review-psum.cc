class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> psum(n+1, 0);
        for(int i = 0; i < n; i++){
            psum[i+1] = psum[i] + nums[i];
        }
        // psum[j]-psum[i] represents the sum of [i, j)
        // This problem becomes:
        // for each j (ending position):
        //    find the smallest psum[i] in front of it
        int min_psum_i = psum[0];
        int ans = INT_MIN;
        for(int j = 1; j <= n; j++){
            // [i, j)
            ans = max(ans, psum[j]-min_psum_i);            
            min_psum_i = min(min_psum_i, psum[j]);
        }
        return ans;
    }
};
