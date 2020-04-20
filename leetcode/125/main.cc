bool check(string &s){
    for(int i = 0, j = s.length()-1; i < j;){
        char s_i = tolower(s[i]);
        char s_j = tolower(s[j]);
        // ignore not alphanum
        if(isalnum(s_i) == 0){
            i++;
            continue;
        }
        // ignore not alphanum
        if(isalnum(s_j) == 0){
            j--;
            continue;
        }
        if(s_i != s_j){
            return false;
        }
        i++, j--;
    }
    return true;
}

class Solution {
public:
    bool isPalindrome(string s) {
        return check(s);
    }
};
