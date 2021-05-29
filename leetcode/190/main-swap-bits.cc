class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1, rev_mask = 1 << 31;
        for(int i = 0; i < 16; i++, mask <<= 1, rev_mask >>= 1){
            // Swap i and 31-i bits
            n = ((n & ~mask) & ~rev_mask) | (((n & mask) << (31-i-i))
                 | ((n & rev_mask) >> (31-i-i)));
        }
        return n;
    }
};
