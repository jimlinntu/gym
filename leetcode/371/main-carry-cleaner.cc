class Solution {
public:
    int getSum(int a, int b) {
        // If they will still generate carry bits
        while(b != 0){
            int carry = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        // if they do not generate carry bits anymore, we will just add them together
        return a;
    }
};
