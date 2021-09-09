class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n), right(n);
        // Divide the nums into ceil(nums / k) parts
        // Case 1: a sliding window align a part
        // Case 2: a sliding window cross two parts
        for(int i = 0; i < n; i++){
            if(i % k == 0){
                left[i] = nums[i];
            }else{
                left[i] = max(left[i-1], nums[i]);
            }
            int j = n-1-i;
            // the last one or the first one from the right for this part
            if(j + 1 >= n or j % k == k-1){
                right[j] = nums[j];
            }else{
                right[j] = max(right[j+1], nums[j]);
            }
        }
        vector<int> ans;
        for(int i = k-1; i < n; i++){
            int mx;
            // Case 1: perfectly aligned
            if(i % k == k-1){
                mx = left[i];
            }else{
                // Case 2: span across two parts
                mx = max(left[i], right[i-k+1]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
