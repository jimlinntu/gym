// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        // [1, n] -> [0, n-1]
        // [F F F F T T T T T]
        //          ^ find the lefmost one
        while(l < r){
            // NOTE: l + r will overflow
            int mid = l + (r - l) / 2;
            int ret = isBadVersion(mid+1);
            // find leftmost true
            if(ret){
                // [l, mid)
                r = mid;
            }else{
                // [mid+1, r)
                l = mid+1;
            }
        }
        if(l == n) return -1; // there is no bad version
        return l+1; // [0, n-1] -> [1, n]
    }
};
