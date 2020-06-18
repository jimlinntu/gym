class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        // put x in nums[x-1]
        for(int i = 0; i < n; i++){
            // put j to the right place
            int j = nums[i];
            // Note: 1 <= j <= n must be true
            // nums[j-1] has not become j,
            // put j to nums[j-1]
            while(nums[j-1] != j){
                swap(nums[i], nums[j-1]);
                j = nums[i];
            }
        }
        // If nums[x] != x+1, then this is
        vector<int> rets;
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1){
                rets.push_back(i+1);
            }
        }
        return rets;
    }
};
