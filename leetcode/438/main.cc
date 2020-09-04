class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        vector<int> indices;
        if(n > m) return indices;
        vector<int> holes(26, 0);
        // dig the holes by string p
        for(int i = 0; i < n; i++){
            holes[p[i]-'a']--;
        }
        int l = 0, r = 0;
        while(r < m){
            int r_idx = s[r++] - 'a';
            holes[r_idx]++;
            while(l < r and holes[r_idx] > 0){
                holes[s[l++]-'a']--;
            }
            // if sum(holes) == 0
            if(r - l == n) indices.push_back(l);
        }
        return indices;
    }
};
