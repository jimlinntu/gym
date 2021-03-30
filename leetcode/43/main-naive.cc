class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        // Ex. 999 * 9999 == 9989001 == 7 digits
        vector<int> ans(m+n, 0);
        int carry = 0;
        int new_n = 1; // handle 0 * x case
        // ans[i] represent the i-th digit of the ans_str
        for(int i = 0; i < m+n; i++){
            int digit = carry;
            // ans[i] = sum(reverse(num1)[j] * reverse(num2)[i-j] for all j)
            // Because j + i - j == i
            // This is convolution!
            for(int j = 0; j <= min(i, m-1); j++){
                if(i-j > n-1) continue;
                digit += (num1[m-1-(j)]-'0') * (num2[n-1-(i-j)]-'0');
            }
            ans[i] = digit % 10;
            carry = digit / 10;
            if(ans[i] > 0) new_n = i+1;
        }
        string ans_str;
        for(int i = new_n-1; i >= 0; i--){
            ans_str.push_back(ans[i]+'0');
        }
        return ans_str;
    }
};
