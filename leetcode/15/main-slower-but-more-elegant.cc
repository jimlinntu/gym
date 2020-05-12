class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answers;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            // Avoid duplicate numbers
            if(i > 0 && nums[i-1] == nums[i]) continue;
            if(nums[i] > 0) break; // Trick! if nums[i] > 0 then, nums[j] + nums[k] != -nums[i] because nums[j] + nums[k] > 0
            // find j, k such that nums[j] + nums[k] == -nums[i]
            int target = -nums[i];
            // Two pointers two sum algorithm
            int k = n-1;
            for(int j = i+1; j < k; j++){
                // Avoid duplicate numbers
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                // decrement k when nums[j] + nums[k] > target
                
                // Note: be careful of j < k condition!!
                while(j < k && nums[j] + nums[k] > target){
                    k--;
                }
                // if a two sum is found
                if(j < k && nums[j] + nums[k] == target){
                    answers.push_back(vector<int>({nums[j], nums[k], -target}));
                }
            }
        }
        return answers;
    }
};
