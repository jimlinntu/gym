class Solution {
public:
    const int n = 1 << 8;
    const int mask = n-1; // 11111111
    int count[1 << 8];
    void precompute(){
        for(int i = 0; i < n; i++){
            int num = i;
            int c = 0;
            for(; num > 0; num = num & (num-1)){
                c++;
            }
            count[i] = c;
        }
    }
    int hammingWeight(uint32_t num) {
        precompute();
        return count[num & mask] + count[(num >> 8) & mask] +
               count[(num >> 16) & mask] + count[(num >> 24) & mask];
    }
};
