class Solution {
public:
    string addBinary(string a, string b) {
        // Ex. 1111 + 111 == 10110 == five bits
        int m = a.size();
        int n = b.size();
        int max_size = max(m, n)+1;
        int true_size = 1;
        string ans(max_size, '0');
        int carry = 0;
        for(int i = 0; i < max_size; i++){
            int bit = carry;
            if(i < m) bit += a[m-1-i]-'0';
            if(i < n) bit += b[n-1-i]-'0';
            ans[i] = (bit % 2) + '0';
            carry = bit / 2;
            if(ans[i]-'0' > 0) true_size = i+1;
        }
        // Reverse this string
        return string(ans.rbegin()+(max_size-true_size), ans.rend());
    }
};
