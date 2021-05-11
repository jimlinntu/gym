class Solution {
public:
    int n;
    void reverse(vector<int> &a, int sidx){
        int start = sidx, end = n-1;
        while(start < end){
            swap(a[start++], a[end--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        n = nums.size();
        // Find the largest index k such that a[k] < a[k + 1]
        int k = -1, l = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
        if(k == -1){
            reverse(nums, 0);
            return;
        }
        // Find the largest index l greater than k such that a[k] < a[l].
        for(int i = k+1; i < n; i++){
            if(nums[i] > nums[k]){
                l = i;
            }
        }
        assert(l != -1); // at least it can be k+1 (nums[k] < nums[k+1])
        // Swap the value of a[k] with that of a[l]
        swap(nums[k], nums[l]);
        reverse(nums, k+1);
    }
};
