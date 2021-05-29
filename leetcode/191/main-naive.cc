class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(; n > 0; n >>= 1){
            count += (n & 1);
        }
        return count;
    }
};
