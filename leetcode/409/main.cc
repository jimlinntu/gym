class Solution {
private:
    // a-z, A-Z
    int count[52];
public:
    int char2idx(char c){
        if((int)c >= 97) return c-'a';
        return c-'A'+26;
    }
    int longestPalindrome(string s) {
        memset(count, 0, sizeof(count));
        bool has_odd = false;
        int n = s.length();
        for(int i = 0; i < n; i++){
            count[char2idx(s[i])]++;
        }
        int len = 0;
        for(int i = 0; i < 52; i++){
            has_odd |= count[i] % 2;
            len += (count[i] / 2) * 2;
        }
        return len + (int)has_odd;
    }
};
