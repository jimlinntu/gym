class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int max_product = nums[0];
        // the maximum and minimum up to the current index i
        // Notice that by definition, imax >= imin
        int imax = max_product, imin = max_product;
        // Starting from i == 1
        for(int i = 1; i < n; i++){
            int num = nums[i];
            int cur_imax, cur_imin;
            if(num > 0){
                if(imax > 0){
                    cur_imax = num * imax;
                }else if(imax == 0){
                    cur_imax = num;
                }else{
                    cur_imax = num;
                }

                if(imin > 0){
                    // imin * num > num, so we choose num
                    cur_imin = num;
                }else if(imin == 0){
                    cur_imin = 0;
                }else{
                    // imin < 0, so imin * num can generate the smallest product
                    cur_imin = imin * num;
                }

                imax = cur_imax;
                imin = cur_imin;
            }else if(num == 0){
                // the maximum and minimum of the product up to i
                // can only be zero
                imax = imin = 0;
            }else{
                if(imin > 0){
                    // if the minimum up to i-1 is > 0
                    // then (imax * num) or (imin * num) will all <= num
                    // Thus we choose num here
                    cur_imax = num;
                }else if(imin == 0){
                    // Because num is negative, multiply it by zero
                    // will always bigger
                    cur_imax = 0;
                }else{
                    // Because imin is negative
                    // imin * num can generate a larger product
                    cur_imax = num * imin;
                }

                if(imax > 0){
                    // because num < 0, num * imax
                    cur_imin = num * imax;
                }else if(imax == 0){
                    // imin <= 0, so imin * num >= 0, num is always smaller
                    cur_imin = num;
                }else{
                    // imax < 0, imax * num > 0
                    // choose num
                    cur_imin = num;
                }

                imax = cur_imax;
                imin = cur_imin;
            }
            max_product = max(max_product, imax);
        }
        return max_product;
    }
};
