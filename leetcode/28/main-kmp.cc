class Solution {
public:
    void kmp(vector<int> &lps, string &p){
        int n = p.size();
        int len = 0;
        lps[0] = 0;
        for(int i = 1; i < n; i++){
            while(len != 0 and p[len] != p[i]){
                len = lps[len-1];
            }
            if(p[len] == p[i]) lps[i] = ++len;
            else lps[i] = 0;
        }
    }
    int strStr(string t, string p) {
        if(p.size() == 0) return 0;
        // check if t(text) contains p(pattern)
        vector<int> lps(p.size());
        kmp(lps, p);
        
        int m = t.size(), n = p.size();
        // i is the index for t
        // j is the index for p (p[j] will be the next character we want to compare)
        for(int i = 0, j = 0; i < m;){
            while(i < m and j < n and t[i] == p[j]){
                i++, j++;
            }
            // find a match
            if(j == n) return i-n;
            // if do not find a match, move j to the next position using lps
            if(j == 0) i++; // move i to the right
            else{
                // the next character in p we want to compare
                j = lps[j-1];
            }
        }
        return -1;
    }
};
