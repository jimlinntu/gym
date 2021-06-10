class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void two_sum(vector<int> &nums, int i, int target){
        int l = i, r = n-1;
        while(l < r){
            int s = nums[l] + nums[r];
            if(s == target){
                // https://leetcode.com/problems/3sum/discuss/7380/Concise-O(N2)-Java-solution
                ans.push_back({nums[i-1], nums[l], nums[r]});
                // move l until a new number
                // move r until a new number
                int j;
                for(j = l; j < r and nums[l] == nums[j]; j++){}
                l = j;
                for(j = r; l < j and nums[r] == nums[j]; j--){}
                r = j;
            }else if(s > target){
                r--;
            }else{
                l++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        if(n < 3) return {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            // avoid duplicates
            if(i > 0 and nums[i-1] == nums[i]) continue;
            two_sum(nums, i+1, -nums[i]);
        }
        return ans;
    }
};
