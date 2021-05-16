class Solution {
public:
    int ans = 0;
    int n;
    void extend(string &s, int l, int r){
        while(0 <= l and r < n and s[l] == s[r]){
            ans++;
            l--, r++;
        }
    }
    int countSubstrings(string s) {
        n = s.size();
        // O(n^2)
        for(int i = 0; i < n; i++){
            extend(s, i, i);
            extend(s, i, i+1);
        }
        return ans;
    }
};
