class Solution {
public:
    int n;
    void ksum(vector<vector<int>> &ans, vector<int> &nums, int target, int k,
                             int start){
        // two sum
        if(k == 2){
            // Two pointers
            int l = start, r = n-1;
            while(l < r){
                int s = nums[l] + nums[r];
                if(s < target){
                    l++;
                }else if(s > target){
                    r--;
                }else{
                    // Handle cases like:
                    // 2 2 2 4 5 7 7 7 7 7 7
                    if(l >= start+1 and r <= n-2 and
                            nums[l-1] == nums[l]){
                        // do nothing
                    }else ans.push_back({nums[l], nums[r]});
                    l++, r--;
                }
            }
            return;
        }
        int ans_n = ans.size();
        for(int i = start; i < n; i++){
            // avoid duplicates
            if(i >= start+1 and nums[i-1] == nums[i]) continue;

            // Recursion
            ksum(ans, nums, target-nums[i], k-1, i+1);

            // add nums[i] to the newly added set
            for(int j = ans_n; j < ans.size(); j++){
                ans[j].push_back(nums[i]);
            }
            ans_n = ans.size();
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<vector<int>> ans;
        ksum(ans, nums, target, 4, 0);
        return ans;
    }
};
