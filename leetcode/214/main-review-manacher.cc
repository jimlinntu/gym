class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() == 0) return "";
        string S = "#";
        for(int i = 0; i < s.size(); i++){
            S.push_back(s[i]);
            S.push_back('#');
        }
        vector<int> P(S.size(), 0);
        int best_center = -1;
        int n = S.size();
        int c = -1, r = -1;
        for(int i = 0; i < n; i++){
            if(i < r and i + P[2*c-i] != r-1){
                // Case 1: i + P[i'] < r-1
                // Case 3: i + P[i'] > r-1
                P[i] = min(P[2*c-i], r-1-i);
            }else{
                // need to expand it
                r = max(r, i);
                c = i;
                int l = 2*c - r;
                // center expansion
                while(0 <= l and r < n and S[l] == S[r]){
                    l--, r++;
                }
                P[i] = r-1-i;
            }
            // if i - P[i] == 0, then this is a possible candidate
            // because it can form a palindrome touching the starting character
            // centered at i
            if(i - P[i] == 0){
                best_center = i; // record the rightmost
            }
        }
        int true_palin_len = P[best_center] / 2 * 2 + (S[best_center] != '#');
        int num_need = s.size() - true_palin_len;
        return string(s.rbegin(), s.rbegin()+num_need) + s;
    }
};
