class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        assert(n >= 1);
        // Thinking process:
        // Ex.
        // 8392 (4 digits)
        // Case 1: 1~3 digits
        // Case 2: 4 digits
        //
        // Case 1: 1~3 digits:
        // Simple, because for example, XXX -> 9(leading digit can not be 0) * 9 * 8
        // Case 2: is complicated
        // 8392 ->:
        // 1XXX ~ 7XXX   ([1, 8))
        // 80XX ~ 82XX   ([0, 3))
        // 830X ~ 838X   ([0, 9))
        // 8390 ~ 8392   ([0, 2])
        //                    ^ <-- notice this row is 8392
        int num_digits = 0;
        // 8392 -> [2, 9, 3, 8]
        vector<int> digits;
        for(int nn = n; nn > 0; nn /= 10){
            num_digits++;
            digits.push_back(nn % 10); // extract the last digit
        }
        // 1~9
        if(num_digits == 1) return 0;
        // Case 1: case1dp[i] == the number of i digits numbers w/o repeated digits
        int num_wo_repeated = 0;
        vector<int> case1dp(num_digits);
        // X
        case1dp[1] = 9; // 1~9 (no 0)
        num_wo_repeated += case1dp[1];
        // if num_digits > 10, then we cannot create any numbers w/o repeated digits
        for(int i = 2; i < min(num_digits, 10+1); i++){
            // i digits: XXX...X
            case1dp[i] = case1dp[i-1] * (10 - (i-1)); // (i-1) already decided
            num_wo_repeated += case1dp[i];
        }

        // Case 2:
        // In order to form a `num_digits` number <= N
        // we have to be careful
        // Ex. 8392
        // Observe XXXX has a recursive structure
        // Let's say we already know XXX (the first 3 digits)
        // f(XXX) * (10-3) should be answer, is it right?
        // NO! Because if XXX = 839, 8393~8399 are invalid!
        // so f(XXXX) should be f(XXX) * (10-3) - (9-2)
        // Is it right? Still NO!
        // because 8399 is not selected when we compute f(XXX) * (10-3) (`9` is in that 3),
        // we should only remove those > N numbers when it is not appearing in the prefix
        // so 8394, 8395, 8396, 8397 are those numbers we need to subtract
        // --> f(XXXX) = f(XXX) * (10-3) - 4

        // Ex. 8392, then prefix = {8} -> {8, 3} -> {8, 3, 9}
        vector<bool> prefix(10, false);
        bool has_duplicate = false;
        int case2dp = 1;
        // start from the least significant digit
        for(int i = 0; i < num_digits; i++){
            // NOTE: 8392 -> [2, 9, 3, 8]
            int d = digits[num_digits-1-i];
            // Ex. XXX -> XXX0 ~ XXX9 (more precisely) f(XXX) * (10-3)
            case2dp *= (i == 0)? (9):(10-i); // -i means there are i digits already chosen
            // XXX0~XXX9 might include numbers > N,

            if(has_duplicate) continue;
            // Fix > N issues
            int subtract = 0;
            for(int j = d+1; j < 10; j++){
                // if this digit `j` is included in f(XXX) * (10-3)
                if(!prefix[j]) subtract++;
            }
            // remove those > N ones
            case2dp -= subtract;
            // record duplicates (bounday checking)
            if(prefix[d]){
                // if this prefix[d] already appear before
                // case2p * = (10-i) does not select this `d`!
                has_duplicate = true;
            }else prefix[d] = true;
        }
        num_wo_repeated += case2dp;
        return n - num_wo_repeated;
    }
};
