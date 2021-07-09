class Solution {
public:
    vector<int> lsp;
    int kmp(string &S){
        int n = S.size();
        int len = 0;
        // S[0]~S[0]'s longest proper prefix which is also a suffix
        lsp[0] = 0;
        for(int i = 1; i < n; i++){
            while(S[len] != S[i]){
                if(len == 0) break;
                // S[0]~S[len-1]
                len = lsp[len-1];
            }

            if(S[len] == S[i]) lsp[i] = ++len;
            else lsp[i] = 0;
        }
        return lsp[n-1];
    }
    string shortestPalindrome(string s) {
        if(s.size() == 0) return "";
        string rev_s(s.rbegin(), s.rend());
        string S = s + "#" + rev_s;
        lsp = vector<int>(S.size(), 0);

        int max_len = kmp(S); // the longest prefix palindrome
        int num_char_need_to_add = s.size() - max_len;
        return string(s.rbegin(), s.rbegin()+num_char_need_to_add) + s;
    }
};
