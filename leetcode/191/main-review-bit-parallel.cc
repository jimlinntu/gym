class Solution {
public:
    int hammingWeight(uint32_t num) {
        uint32_t mask1 = 0xaaaaaaaa;
        uint32_t mask2 = 0xcccccccc;
        uint32_t mask3 = 0xf0f0f0f0;
        uint32_t mask4 = 0xff00ff00;
        uint32_t mask5 = 0xffff0000;
        // Bitwise parallel computing
        // # of operations: O(log2 32) == O(5)
        num = ((num & mask1) >> 1) + (num & (mask1 >> 1));
        num = ((num & mask2) >> 2) + (num & (mask2 >> 2));
        num = ((num & mask3) >> 4) + (num & (mask3 >> 4));
        num = ((num & mask4) >> 8) + (num & (mask4 >> 8));
        num = ((num & mask5) >> 16) + (num & (mask5 >> 16));
        return num;
    }
};
