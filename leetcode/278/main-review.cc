// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n-1;
        // FFFFTTTT
        //     ^ this one
        while(l <= r){
            int mid = l + (r-l)/2;
            bool ret = isBadVersion(mid+1);
            if(ret){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        if(l == n) return -1; // no bad version
        return l+1;
    }
};
