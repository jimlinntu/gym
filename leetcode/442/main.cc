class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int j = nums[i];
            while(1 <= j and j <= n and j != nums[j-1]){
                swap(nums[j-1], nums[i]);
                j = nums[i];
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1) ans.push_back(nums[i]);
        }
        return ans;
    }
};
