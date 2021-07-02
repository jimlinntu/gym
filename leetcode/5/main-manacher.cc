class Solution {
public:
    string longestPalindrome(string s) {
        string S = "#";
        for(char c: s){
            S.push_back(c);
            S.push_back('#');
        }
        int n = S.size();
        // P[i] == S[i-P[i]] ~ S[i+P[i]] forms the longest palindrome
        vector<int> P(n, 0);
        int c = -1, r = -1;
        bool expand = false;
        // answer-related
        int max_idx = 0;
        int max_len = 0;
        for(int i = 0; i < n; i++){
            // NOTE: in practice: r is open rather than closed
            // i.e. ... ~ S[c] ~ S[r-1] forms a palindrome
            // if i < r, we use the mirror property
            expand = false;
            if(i < r){
                int mirror_i = 2 * c - i;
                // Case 2: i + P[mirror] == r-1
                if(i + P[mirror_i] == r-1) expand = true;
                else P[i] = min(P[mirror_i], r-1-i);
                // Case 1: i + P[mirror] does not touch the boundary
                // Case 3: i + P[mirror] expand beyond the boundary
            }else if(i >= r){
                // if i >= r, we use center expansion and move r to the right
                expand = true;
            }

            // need to expand
            if(expand){
                // set c to this i and then perform center expansion
                int l;
                // NOTE: r = max(r, i) is the key to reduce this to O(n) because
                //       it will not walk backward
                r = max(r, i);
                c = i;
                l = 2 * c - r; // mirror of r
                while(0 <= l and r < n and S[l] == S[r]){
                    l--, r++;
                }
                // the longest palindrome diameter for this index
                P[i] = r - c - 1;
                // note: (l, r) is open on both sides
            }

            if(P[i] > max_len){
                max_len = P[i];
                max_idx = i;
            }
        }
        string true_ans;
        for(int i = max_idx - P[max_idx]; i <= max_idx + P[max_idx]; i++){
            if(S[i] != '#') true_ans.push_back(S[i]);
        }
        return true_ans;
    }
};
