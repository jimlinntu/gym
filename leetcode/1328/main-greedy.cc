class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.size();
        if(n == 1) return ""; // infeasible
        int idx = -1;
        for(int i = 0; i < n/2; i++){
            if(p[i] != 'a'){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            p[idx] = 'a';
            return p;
        }
        // All characters are a
        // i.e. aaaaaa....aaaaa
        p[n-1] = 'b';
        return p;
    }
};
