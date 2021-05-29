class Solution {
public:
    int ans = 0;
    int n;
    void solve(string &s, int i){
        if(i >= n){
            ans++;
            return;
        }
        // Character starting from 0 must be invalid
        if(s[i] == '0') return;
        // One character can only be 1-9
        solve(s, i+1);

        if(i == n-1) return;
        int num = 10 * (s[i] -'0') + s[i+1] - '0';
        if(num < 1 or num > 26) return;
        solve(s, i+2);
    }
    int numDecodings(string s) {
        n = s.length();
        solve(s, 0);
        return ans;
    }
};
