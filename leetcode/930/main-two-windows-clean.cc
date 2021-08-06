class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0;
        int win_i = 0, win_j = 0;

        int ans = 0;
        int n = nums.size();

        for(int k = 0; k < n; k++){
            // ending at k
            win_i += nums[k];
            win_j += nums[k];
            
            // sum(nums[i] ~ nums[k])
            // NOTE: i < k will force [i, k] to have at least one element
            // NOTE: [1, 1, 0, 1, 0], goal = 0
            //        ^
            //      i,j,k all point here
            while(i < k and win_i > goal){
                win_i -= nums[i++];
            }
            // Ex. [0, 0, 0, 1, 0, 1], goal = 2
            //      i        j     k
            
            while(j < k and (win_j > goal or (win_j == goal and nums[j] == 0))){
                win_j -= nums[j++];
            }
            
            if(win_i == goal){
                ans += j-i+1;
            }

        }
        return ans;
    }
};
