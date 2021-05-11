class Solution {
public:
    int nthUglyNumber(int n) {
        // Multiplication heads
        // we will always multiple things at mulX by X
        int mul2 = 0, mul3 = 0, mul5 = 0;
        vector<int> ugly_nums(n);
        ugly_nums[0] = 1;
        for(int i = 1; i < n; i++){
            ugly_nums[i] = min({ugly_nums[mul2]*2, ugly_nums[mul3]*3, ugly_nums[mul5]*5});
            if(ugly_nums[i] == ugly_nums[mul2] * 2) mul2++;
            if(ugly_nums[i] == ugly_nums[mul3] * 3) mul3++;
            if(ugly_nums[i] == ugly_nums[mul5] * 5) mul5++;
        }
        return ugly_nums[n-1];
    }
};
