class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> indices(n);
        for(int i = 0; i < n; i++) indices[i] = i;
        sort(indices.begin(), indices.end(),
             [&nums](const int &l, const int &r) -> bool{
            return nums[l] < nums[r];
        });
        
        int l = 0, r = n-1;
        while(l < r){
            int s = nums[indices[l]] + nums[indices[r]];
            if(s == target) return {indices[l], indices[r]};
            else if(s > target){
                r--;
            }else{
                l++;
            }
        }
        return {};
    }
};
