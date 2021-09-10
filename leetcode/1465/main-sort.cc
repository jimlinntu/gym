using LL = long long int;
#define MOD 1000000007LL
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        int m = hcuts.size();
        int n = vcuts.size();
        hcuts.push_back(0);
        hcuts.push_back(h);
        vcuts.push_back(0);
        vcuts.push_back(w);
        sort(hcuts.begin(), hcuts.end());
        sort(vcuts.begin(), vcuts.end());
        
        int max_h = 0, max_w = 0;
        for(int i = 1; i <= m+1; i++){
            int rect_h = hcuts[i]-hcuts[i-1];
            max_h = max(max_h, rect_h);
        }
        for(int j = 1; j <= n+1; j++){
            int rect_w = vcuts[j]-vcuts[j-1];
            max_w = max(max_w, rect_w);
        }
        return ((LL)max_h * (LL)max_w) % MOD;
    }
};
