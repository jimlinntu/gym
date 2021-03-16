class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // because 0 <= num <= 100, we can simply use an array
        // if there is no constraint, we should use an map
        int psum[101] = {0};
        for(int i = 0; i < n; i++){
            psum[nums[i]]++;
        }
        // compute prefix sum
        for(int i = 1; i < 101; i++){
            psum[i] = psum[i] + psum[i-1];
        }

        for(int i = 0, num; i < n; i++){
            num = nums[i];
            if(num > 0) ans[i] = psum[num-1];
            else ans[i] = 0;
        }
        return ans;
    }
};
