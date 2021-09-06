class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int freq[2] = {0};
        for(int i = 0; i < n; i++){
            if(i > 0 and s[i-1] != s[i]){
                // update ans
                ans += min(freq[0], freq[1]);
                // reset s[i]
                freq[s[i]-'0'] = 1;
            }else{
                freq[s[i]-'0']++;
            }
        }
        return ans + min(freq[0], freq[1]);
    }
};
