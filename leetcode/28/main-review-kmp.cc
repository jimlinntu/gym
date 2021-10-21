class Solution {
public:
    // compute the longest prefix also suffix
    void compute_lps(string &s, vector<int> &lps){
        int n = lps.size();
        int len = lps[0] = 0;
        for(int i = 1; i < n; i++){
            while(len != 0 and s[len] != s[i]){
                len = lps[len-1]; // shorter prefix and suffix
            }
            if(s[len] == s[i]) lps[i] = ++len;
            else len = 0;
        }
    }
    int strStr(string s, string t) {
        int n = t.size();
        if(n == 0) return 0;
        vector<int> lps(n);
        compute_lps(t, lps);

        for(int i = 0, j = 0; i < s.size();){
            if(s[i] == t[j]){
                i++, j++;
            }else{
                if(j > 0) j = lps[j-1];
                else i++; // no way to match, move on
            }
            
            if(j == n) return i-n;
        }
        return -1;
    }
};
