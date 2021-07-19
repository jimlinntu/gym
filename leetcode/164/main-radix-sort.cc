class Solution {
public:
    void radix_sort(vector<int> &nums){
        int n = nums.size();
        if(n == 0) return;
        int M = *max_element(nums.begin(), nums.end());
        const int b = 10;
        int count[b] = {0};
        vector<int> out(n);
        // sort from the least sig digit to the most sig digit
        for(int exp = 1; exp <= M; exp *= b){
            fill(count, count+b, 0);
            // counting sort
            for(int num: nums){
                count[(num / exp) % b]++;
            }
            // make it an index
            for(int i = 1; i < b; i++){
                count[i] += count[i-1];
            }
            // place the numbers into their indices
            for(int i = n-1; i >= 0; i--){
                out[--count[(nums[i] / exp) % b]] = nums[i];
            }
            // copy out backed to nums
            nums = out;
        }
        
    }
    int maximumGap(vector<int>& nums) {
        radix_sort(nums);
        // Find the maximal diff
        int ans = 0;
        for(int i = 1; i < nums.size(); i++)
            ans = max(ans, nums[i]-nums[i-1]);
        return ans;
    }
};
