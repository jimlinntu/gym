class Solution {
public:
    string transform(string s){
        // Ex. abc -> #a#b#c#
        string t = "#";
        for(char c: s){
            t.push_back(c);
            t.push_back('#');
        }
        return t;
    }
    // compute the mirror of i about c
    int mirror(int i, int c){
        return 2*c - i;
    }
    int countSubstrings(string s) {
        string t = transform(s);
        // Manacher's algorithm
        // radius[i] ==
        // t[i] - radius[i] ~ t[i] ~ t[i] + radius[i] can form the longest palindrome
        // centered at t[i]
        int n = t.size();
        vector<int> radius(n);
        int C = 0;
        int L = C, R = C;
        while(C < n){
            // Expand L, R about C
            while(0 <= L and R < n and t[L] == t[R]){
                L--, R++;
            }
            // (L, R) can form the longest palindrome about C
            // NOTE: The ends of this set are open.
            radius[C] = R-C-1;
            int i;
            for(i = C+1; i < R; i++){
                int i_prime = mirror(i, C);
                int l = i_prime - radius[i_prime];

                if(l > L+1){
                    // If the palindrome at i_prime does not touch t[L+1]
                    radius[i] = radius[i_prime];
                }else if(l == L+1){
                    // If the palindrome at i_prime touch t[L+1]
                    break;
                }else{
                    // If the palindrome at i_prime expand beyond t[L+1]
                    radius[i] = i_prime - (L+1);
                }
            }

            C = i;
            if(C >= R){
                // if it is in a new section
                // we set L, R to C
                L = R = C;
            }else{
                // if C is still in (L, R)
                // we set the boundary of L to mirror(R, C)
                L = mirror(R, C);
            }
        }
        // Accumulate the number of palindromes
        int ans = 0;
        for(int i = 0; i < n; i++){
            // Ex.
            // #a#a#a#
            // ..23... 
            ans += (radius[i]+1) / 2;
        }
        return ans;
    }
};
