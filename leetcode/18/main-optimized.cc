class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answers;
        int n = nums.size();
        if(n < 4) return answers;
        sort(nums.begin(), nums.end());
        // Total: O(n^2) * O(n) = O(n^3)
        for(int i = 0; i < n-3; i++){
            // Skip duplicate numbers
            if(i > 0 && nums[i-1] == nums[i]) continue;
            // If the smallest 4 sum is already larger than target, then break
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            // If the current nums[i] and the largest three number cannot be larger than target, then skip this index
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                // Two sum: O(n) algorithm
                int goal = target - nums[i] - nums[j];
                int end = n-1;
                for(int k = j+1; k < n-1; k++){
                    if(k > j+1 && nums[k-1] == nums[k]) continue;
                    // Keep decrement end until nums[k] + nums[end] <= goal
                    while(k < end && nums[k] + nums[end] > goal){
                        end--;
                    }
                    if(k < end && nums[k] + nums[end] == goal){
                        answers.push_back(
                            vector<int>({nums[i], nums[j], nums[k], nums[end]}));
                    }
                }
            }
        }
        return answers;
    }
};
