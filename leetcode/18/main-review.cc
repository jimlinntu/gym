class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        // Overall: O(nlogn) + O(n^2)
        for(int i = 0; i < n-3; i++){
            if(i >= 1 and nums[i-1] == nums[i]) continue; // duplicates
            // 3 sum
            for(int j = i+1; j < n-2; j++){
                if(j >= i+2 and nums[j-1] == nums[j]) continue;
                // Two sum
                int t = target - nums[i] - nums[j];
                // two pointers
                int l = j+1, r = n-1;
                while(l < r){
                    int s = nums[l] + nums[r];
                    if(s > t){
                        // move the right pointer
                        r--;
                    }else if(s < t){
                        l++;
                    }else{
                        // Ex. 2 2 3 4 5 5 5
                        if(j+2 <= l and r <= n-2 and nums[l-1] == nums[l] and
                           nums[r] == nums[r+1]){
                        }else ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                    }
                }
            }
        }
        return ans;
    }
};
