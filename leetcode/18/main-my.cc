class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answers;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // Total: O(n^2) * O(n) = O(n^3)
        for(int i = 0; i < n; i++){
            // Skip duplicate numbers
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                // Two sum: O(n) algorithm
                int goal = target - nums[i] - nums[j];
                int end = n-1;
                for(int k = j+1; k < n; k++){
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
