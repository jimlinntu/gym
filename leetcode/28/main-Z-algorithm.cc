class Solution {
public:
    int strStr(string t, string p) {
        if(p.size() == 0) return 0;
        string S = p + "#" + t;
        cout << S << endl;
        // z[i] == the length of the longest substring starting from S[i]
        //         which is also the prefix of S
        int m = t.size();
        int n = p.size();
        int N = m+1+n;
        // Z algorithm (like Manacher's algorithm's idea)
        vector<int> z(N);
        int l = -1, r = -1;
        for(int i = 1; i < N; i++){
            // inside the window, use the prefix information
            // if i + z[i-l] touchs the right end, we know we must expand
            if(i < r and i + z[i-l] != r){
                // Case 1: i + z[i-l] < r
                // Case 3: i + z[i-l] > r
                z[i] = min(z[i-l], r-i);
            }else{
                r = max(r, i);
                l = i;
                int k = r-l;
                // expand right
                while(r < N and S[k] == S[r]){
                    k++, r++;
                }
                // the length of the longest substring which is also the prefix
                z[i] = r-l;
            }
            // if the length == the length of p, then we find a match
            if(z[i] == n) return i-n-1;
        }
        return -1;
    }
};
