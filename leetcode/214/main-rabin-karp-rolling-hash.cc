using LL = long long int;
class Solution {
public:
    vector<int> cand;
    string shortestPalindrome(string s) {
        int n = s.size();
        LL p = 29;
        LL mod = 786433;
        LL prod = 1;
        LL forward_h = 0; // --->
        LL backward_h = 0; // <---

        for(int i = 0; i < n; i++, prod = prod * p % mod){
            char c = s[i];
            forward_h = (forward_h + (LL)(c-'a') * prod) % mod;
            backward_h = (backward_h * p + (LL)(c -'a')) % mod;
            if(forward_h == backward_h){
                cand.push_back(i);
            }
        }
        // search from the rightmost (the longest)
        for(int i = (int)cand.size()-1; i >= 0; i--){
            // check if this is a true palindrome
            int l = 0, r = cand[i];
            while(l <= r and s[l] == s[r]){
                l++, r--;
            }
            if(l > r) return string(s.rbegin(), s.rbegin() + s.size() - cand[i] - 1) + s;
        }
        return "";
    }
};
