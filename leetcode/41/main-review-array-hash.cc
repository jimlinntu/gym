class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Observe: Because this array only has n numbers
        // the largest smallest missing positive number is
        // [1, 2, 3, 4, 5, ... , n] -> n+1
        // We can ignore nonpositive numbers
        // Ex. [a0, a1, a2, a3, a4]
        
        // exist[num] == whether num exists in nums
        vector<bool> exist(n+2, false);
        for(int num: nums){
            if(num <= 0) continue;
            if(num >= n+1) continue;
            exist[num] = true;
        }
        exist[n+1] = false; // force the loop to stop
        for(int i = 1; i <= n+1; i++){
            if(!exist[i]) return i;
        }
        return -1;
    }
};
