class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Observe: Because this array only has n numbers
        // the largest smallest missing positive number is
        // [1, 2, 3, 4, 5, ... , n] -> n+1
        // We can ignore nonpositive numbers
        // Ex. [a0, a1, a2, a3, a4]

        bool has_1 = false;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                has_1 = true;
                break;
            }
        }
        if(!has_1) return 1;
        // Reuse this nums array as a hash table
        // because we know we only need to build a hashtable
        // where ht[1 <= num <= n] = true or false
        // We use +/- as an indicator whether this number exist

        // So we should first transform all <= 0 as 1
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0) nums[i] = 1;
            // ignore it because the largest one is n+1
            if(nums[i] >= n+1) nums[i] = 1;
        }
        // NOTE: nums[num-1] = whether number num exist
        // notice the -1 because our nums only have 0~n-1 slot
        // that's why we need to do a nasty -1
        for(int i = 0; i < n; i++){
            int num = nums[i];
            // flip it back to get the true value
            if(num < 0) num = -num;
            
            // this number has been tagged before
            if(nums[num-1] < 0) continue;
            // Tag it as exisiting
            nums[num-1] = -nums[num-1];
        }
        int ans = 1;
        for(; ans <= n; ans++){
            // + sign => this number doesn't exist
            if(nums[ans-1] > 0) return ans;
        }
        return ans;
    }
};
