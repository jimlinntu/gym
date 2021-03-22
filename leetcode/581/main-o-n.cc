class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int ii = -4, jj = -3;
        int max_ii = nums[0];
        int min_jj = nums[n-1];
        for(int i = 0, j; i < n; i++){
            j = n-i-1;
            // Compute max_i
            max_ii = max(max_ii, nums[i]);
            // Compute max_j
            min_jj = min(min_jj, nums[j]);

            if(max_ii > nums[i]) ii = i;
            if(min_jj < nums[j]) jj = j;
        }
        // nums[ii+1:] and nums[:jj] are sorted!!!
        // nums[jj:ii+1] needs to be sorted!
        return ii-jj+1;
    }
};
