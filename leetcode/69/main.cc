using LL = long long int;
class Solution {
public:
    int mySqrt(int x) {
        // binary search over 1~x
        int left = 1, right = x;
        int mid;
        while(left != right){
            mid = ((LL)left + (LL)right) / 2;
            if((LL)mid * (LL)mid > (LL)x){
                right = mid-1; // [left, mid-1]
            }else{
                // avoid infinite loop
                if(right - left == 1){
                    if((LL)right * (LL)right <= x){
                        // choose the right side
                        left = right = mid+1;
                    }else{
                        // choose the left side
                        left = right = mid;
                    }
                }else{
                    left = mid;
                }
            }
        }
        return left;
    }
};
