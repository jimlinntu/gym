/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return      -1 if num is lower than the guess number
 *      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        while(l < r){
            // l == 0, r == 2 => mid == 1
            // l == 0, r == 3 => mid == 1
            int mid = l + (r - l) / 2;
            int ret = guess(mid+1);
            if(ret <= 0){
                r = mid;
            }else l = mid+1;
        }
        if(l == n) return -1; // not found
        return l+1; // [0, n) -> [1, n]
    }
};
