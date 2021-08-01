class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int lmax = 0, rmax = 0; // lmax == lmax[l], rmax == rmax[r]
        int l = 0, r = n-1;
        int ans = 0;
        while(l <= r){
            if(lmax >= rmax){
                // when lmax[l] is already >= rmax[r]
                // we know that no matter how big is lmax[r]
                // the min(lmax[r], rmax[r]) must be bounded by rmax[r]
                // That's why we can compute the amount of water we can trap
                // at position r
                if(rmax > height[r])
                    ans += rmax-height[r]; // trap water
                rmax = max(rmax, height[r--]);
            }else{
                // when lmax[l] < rmax[r]
                // we know that no matter how big is rmax[l]
                // min(lmax[l], rmax[l]) must be bounded
                // by lmax[l]
                if(lmax > height[l])
                    ans += lmax-height[l];
                lmax = max(lmax, height[l++]);
            }
        }
        return ans;
    }
};
