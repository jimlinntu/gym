class Solution {
public:
    int n;
    vector<string> ans;
    void backtrack(string &s, int i){
        if(i >= n){
            ans.push_back(s);
            return;
        }
        // Not changing
        backtrack(s, i+1);
        if(isdigit(s[i])) return;
        // Changing
        char c = s[i];
        if(isupper(s[i])){
            s[i] = tolower(s[i]);
            backtrack(s, i+1);
            s[i] = c;
        }else{
            s[i] = toupper(s[i]);
            backtrack(s, i+1);
            s[i] = c;
        }
    }
    vector<string> letterCasePermutation(string s) {
        n = s.size();
        backtrack(s, 0);
        return ans;
    }
};
