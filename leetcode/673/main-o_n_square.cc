class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> lengths(n, 1); // each number can form a IS with length 1
        vector<int> counts(n, 1); // each number contain 1 IS (itself)
        int lis_len = 1;
        
        // O(n^2): for each number,
        // search its previous numbers to determine lis_len and counts
        for(int j = 1; j < n; j++){
            for(int i = 0; i < j; i++){
                if(nums[i] >= nums[j]) continue;
                
                // if there is a longest IS, we directly use counts[i]
                if(lengths[i] + 1 > lengths[j]){
                    counts[j] = counts[i]; // reset counts[j] by counts[i]
                    lengths[j] = lengths[i]+1;
                    lis_len = max(lengths[j], lis_len);
                }else if(lengths[i] + 1 == lengths[j]){
                    // if there is a tie,
                    // we add the number of IS with lengths[i] into counts[i]
                    counts[j] += counts[i];
                }// else just ignore this number
            }
        }
        //
        int num_lis = 0;
        for(int i = 0; i < n; i++){
            if(lengths[i] == lis_len) num_lis += counts[i];
        }
        return num_lis;
    }
};
