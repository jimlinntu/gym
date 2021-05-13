class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> c(num+1);
        c[0] = 0;
        for(int i = 1; i <= num; i++){
            c[i] = c[i >> 1] + (i & 1);
        }
        return c;
    }
};
