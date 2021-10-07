class Solution {
public:
    vector<int> countBits(int n) {
        // 0
        // 0 ,1
        // 0,1 ,10,11
        // 0,1,10,11 ,100,101,110,111
        vector<int> ans(n+1);
        ans[0] = 0;
        // BFS (or forward DP)
        int bit = 1;
        for(;bit <= n; bit <<= 1){
            for(int i = 0; i < bit and (i + bit) <= n; i++){
                // turn on that bit (so i must < bit)
                ans[i+bit] = ans[i] + 1;
            }
        }
        return ans;
    }
};
