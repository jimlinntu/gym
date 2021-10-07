class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i >> 1] + (i & 1); // DP
        }
        return ans;
    }
};
