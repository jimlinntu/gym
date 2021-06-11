class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n == 0) return 0;
        int l = 0, r = n;
        while(l < r){
            int mid = (l+r) / 2;
            int h = n - mid; // the distance to the right
            if(c[mid] >= h){
                // [l, mid)
                // NOTE: mid might be a possible sol
                r = mid;
            }else if(c[mid] < h){
                // [mid+1, r)
                // NOTE: mid cannot be the solution
                l = mid+1;
            }
        }
        // NOTE: if h == 0, l must be n because it will fall into l = mid+1
        return n - l;
    }
};
