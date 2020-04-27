class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // the counter 
        //  (x_2: is the most significant bit for nums)
        //  (x_1: is the least significant bit for nums)
        // the r-th bit of (x_2, x_1) this counter
        // represent the counter for r-th bit of all nums
        // the counter will be reset when it reach 3
        int x_2 = 0, x_1 = 0;
        int all_1 = -1; // 11111111... (32 bit)
        int is_equal;
        for(int num: nums){
            // The following two line is actually an adding operation!
            x_2 ^= (x_1 & num); // modify the most significant bit
            x_1 ^= (num); // modify the least significant bit

            // check whether this x_2 x_1 reach 3. If so, reset it to zero
            // Note: 3 == 11 (binary representation)
            // r-th bit of is_equal represent whether r-th bit's counter reach 3
            // Also note that you can accelerate the below line by:
            //  (x_2 & all_1) & (x_1 & all_1) ==
            //  (x_2 & all_1 & x_1) ==
            //  (x_2 & x_1)
            is_equal = (x_2 & all_1) & (x_1 & all_1);
            // If r-th bit of is_equal is true, r-th bit of the counter (x2, x1)
            // will be reset to zero!
            x_2 &= ~is_equal;
            x_1 &= ~is_equal;
            
        }
        // Because p = 1 = 01 (binary represenation),
        // we only need to return x_1
        return x_1;
    }
};
