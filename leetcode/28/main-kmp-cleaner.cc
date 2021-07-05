class Solution {
public:
    vector<int> kmp(string &p){
        // Adapt from:
        // https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
        int n = p.size();
        vector<int> lps(n);
        lps[0] = 0;
        for(int i = 1, len = 0; i < n; ){
            if(p[len] == p[i]){
                len++;
                lps[i] = len;
                i++;
            }else if(len > 0){
                // we choose the shorter prefix
                len = lps[len-1];
            }else{
                // if len reaches 0, and p[0] != p[i]
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }
    int strStr(string t, string p) {
        if(p.size() == 0 ) return 0;
        vector<int> lps = kmp(p);

        int m = t.size(), n = p.size();
        // pattern matching using lps information
        for(int i = 0, j = 0; i < m;){
            // move until we encounter a mismatch
            while(i < m and j < n and t[i] == p[j]){
                i++, j++;
            }
            // find a match
            if(j == n) return i - n;
            // if j == 0, the first character mismatch, move i
            if(j == 0) i++;
            else j = lps[j-1];
        }
        return -1;
    }
};
