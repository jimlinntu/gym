class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Recursive swap (because the depth is 5, we can just unroll it)
        // (Divide and conquer in unrolled form)
        // Ex. abcdefgh
        //  -->efghabcd
        //     ****----
        //  -->ghefcdab
        //     **--**--
        //  ...
        // Swap 16 bits
        n = (n >> 16) | (n << 16);
        // Swap 8 bits
        // NOTE: a hex number represents 4 bits
        n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
        // Swap 4 bits
        n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
        // Swap 2 bits
        // 1100 == c
        // 0011 == 3
        n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;
        // Swap 1 bits
        // 1010 == 8+2 == 10 == a
        // 0101 == 4+1 == 5
        n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;
        return n;
    }
};
