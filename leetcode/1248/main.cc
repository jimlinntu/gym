class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int num_odd = 0;
        int num_nice = 0;
        int num_augment = 0;
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n){
            // Each iteration will add the number of nice subarray starting
            // at i (i.e. the number of all j satisfy
            //       counter of add number in subarray(i, j))
            if(nums[j++] % 2 == 1){
                num_odd++;
            }
            if(num_odd == k){
                // move j to the next occurrence of odd number
                num_augment = 0;
                for(; j < n && nums[j] % 2 == 0; j++){
                    num_augment++;
                }   
            }
            // Start counting the subarray
            for(; i < j && num_odd == k; i++){
                // subarray [i, j) has (1 + num_augment) nice arrays
                num_nice += 1 + num_augment;
                // remove an odd number
                if(nums[i] % 2 == 1) num_odd--;
            }
            
        }
        return num_nice;
    }
};
