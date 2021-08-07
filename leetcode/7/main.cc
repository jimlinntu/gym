class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int result = 0;
        if(x < 0){
            // This negative number's flipped must < -2^31
            if(x == INT_MIN) return 0;
            // NOTE: because no number after flipped can reach INT_MIN(-2^31)
            //       so we can safely turn this number into a positive one
            //       and the process it
            // Because now our number is inside: 
            //    [-2^31+1, 2^31-1]
            // => [-(2^31-1), 2^31-1]
            // Observe that:
            // Given x in [-(2^31-1), 2^31-1]
            // a number x > 0 is "flippable" => a number -x < 0 is "flippable"
            // a number x < 0 is "flippable" => a number -x > 0 is "flippable"
            // Proof:
            // 1. if a number x > 0 is flippable, this means flip(x) <= 2^31-1
            //      => flip(-x) = -flip(x) >= -(2^31-1)
            // 2. if a number x < 0 is flippable, this means flip(x) >= -(2^31-1)
            //      => flip(-x) = -flip(x) <= 2^31-1
            return -reverse(-x);
        }else{
            while(x > 0){
                if(result > INT_MAX / 10) return 0; // overflow
                result *= 10;
                if(result > INT_MAX - (x%10)) return 0; // overflow
                result += x % 10;
                x /= 10;
            }
            return result;
        }
    }
};
