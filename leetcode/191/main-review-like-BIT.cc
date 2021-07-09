class Solution {
public:
    int hammingWeight(uint32_t num) {
        int c = 0;
        // Using the idex of Binary Indexed Tree
        // Actually: n & (n-1) == n - (n & -n)
        // but in this case uint32_t is unsigned
        // so we choose n & (n-1)
        // O(# of bits)
        for(; num > 0; num &= num-1){
            c++;
        }
        return c;
    }
};
