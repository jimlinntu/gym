class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 3) return nums[0] * nums[1] * nums[2];
        assert(n >= 4);
        // Find the lower_bound of 0
        int l = 0, r = n;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] > 0){
                r = mid;
            }else if(nums[mid] == 0){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        // l is the first index s.t. nums[l] >= 0
        int num_neg = l, num_nonneq = n-l;

        auto bit = nums.rbegin();
        if(num_neg <= 1){
            // return the largest 3 numbers' product
            return *bit * (*(bit+1)) * (*(bit+2));
        }else if(num_nonneq >= 3){
            // if num_neq >= 2, we can make the product positive
            // [-50, -30, 1, 2, 3]
            int opt1 = *bit * (*(bit+1)) * (*(bit+2));
            int opt2 = nums[0]*nums[1]*(*bit);
            return max(opt1, opt2);
        }else if(num_nonneq >= 1){
            // if num_neq >= 2 and 1 <= num_nonneq < 3
            // [-50,-30, 1, 2]
            return nums[0]*nums[1]*nums.back();
        }else{
            // if num_seq >= 2 and num_nonneq == 0
            return *bit * (*(bit+1)) * (*(bit+2));
        }
    }
};
