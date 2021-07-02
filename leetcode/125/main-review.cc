class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        while(l <= r){
            char c = s[l], cc = s[r];
            if(!isalnum(c)){
                l++;
                continue;
            }
            if(!isalnum(cc)){
                r--;
                continue;
            }
            c = tolower(c), cc = tolower(cc);
            if(c == cc){
                l++, r--;
            }else break;
        }
        return l > r;
    }
};
