class Solution {
public:
    int strStr(string t, string p) {
        int m = t.size();
        int n = p.size();
        if(n == 0) return 0;
        for(int i = 0; i < m; i++){
            int j;
            for(j = 0; j < n and i+j < m and t[i+j] == p[j]; j++){
            }
            if(j == n) return i;
        }
        return -1;
    }
};
