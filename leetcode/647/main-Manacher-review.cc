class Solution {
public:
    int countSubstrings(string s) {
        string S = "#";
        for(int i = 0; i < s.size(); i++){
            S.push_back(s[i]);
            S.push_back('#');
        }
        vector<int> P(S.size(), 0);
        int count = 0;
        int n = S.size();
        int c = -1, r = -1;
        for(int i = 0; i < n; i++){
            // if we can still use mirror property
            // Case 1: i + P[i'] < r-1 => P[i] = P[i']
            // Case 2: i + P[i'] == r-1 => need to expand
            // Case 3: i + P[i'] > r-1 => P[i] = r-1-i
            if(i < r and i + P[2*c-i] != r-1){
                P[i] = min(P[2*c-i], r-1-i);
            }else{
                // else we should expand it
                r = max(r, i);
                c = i;
                int l = 2*c - r;
                while(0 <= l and r < n and S[l] == S[r]){
                    l--, r++;
                }
                // the longest palindrome of this position
                P[i] = r-1-c;
            }
            // if S[i] != '#', we should count that single character palindrome
            count += P[i] / 2 + (S[i] != '#');
        }
        return count;
    }
};
