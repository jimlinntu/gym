class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;
        int count[3] = {0};
        for(auto num: nums){
            count[num]++;
        }
        int idx = 0;
        for(int i = 0; i < n; i++){
            while(count[idx] == 0) idx++;
            nums[i] = idx;
            count[idx]--;
        }
    }
};
