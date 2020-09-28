class Solution {
public:
    bool ispalindrome(string &s, int mid_l, int mid_r){
        int n = s.length();
        while(mid_l >= 0 and mid_r < n and s[mid_l] == s[mid_r]){
            mid_l--, mid_r++;
        }
        // if there is one side running out of characters,
        // the initial mid_l and mid_r must be the palindrome centers!
        return (mid_l < 0 or mid_r >= n);
    }
    string shortestPalindrome(string s) {
        int n = s.length();
        if(n < 2) return s;
        int mid_l, mid_r;
        if(n % 2){
            mid_l = mid_r = n/2;
        }else{
            mid_l = n/2-1, mid_r = n/2;
        }
        // The palindrome length is assumed to be n at first
        int palin_n = n;
        while(!ispalindrome(s, mid_l, mid_r)){
            // use the centers of mid_l, mid_r cannot form a palindrome
            // even if you can add chars in front of s
            palin_n++;
            if(palin_n % 2){
                // Ex.   f c d e
                //         ^ ^
                //         l r
                //     ? f c d e
                //         ^
                //       (l,r)
                mid_r--;
            }else{
                // Ex.   f c d
                //         ^
                //       (l,r)
                //     ? f c d
                //       ^ ^
                //       l r
                mid_l--;
            }
        }
        string ans(palin_n, 0);
        // Ex. ?aacecaaa
        ans.replace(palin_n-n, n, s);
        // Ex. ?aacecaaa
        //     ^
        //     i    
        for(int i = palin_n-n-1; i >= 0; i--){
            ans[i] = ans[palin_n-i-1];
        }
        return ans;
    }
};
