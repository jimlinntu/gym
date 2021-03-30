class Solution {
public:
    string addStrings(string num1, string num2) {
        // Ex. 999 + 9999 == 10998
        int m = num1.size();
        int n = num2.size();
        int out_size = max(m, n)+1;
        int true_size = 1;
        string ans(out_size, '0');
        int carry = 0;
        for(int i = 0; i < out_size; i++){
            int digit = carry;
            if(i < m) digit += num1[m-1-i]-'0';
            if(i < n) digit += num2[n-1-i]-'0';
            ans[i] = (digit % 10)+'0';
            carry = digit / 10;
            if(ans[i]-'0' > 0) true_size = i+1;
        }
        return string(ans.rbegin()+out_size-true_size, ans.rend());
    }
};
