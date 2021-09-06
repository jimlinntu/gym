class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int freq[2] = {0};
        for(int i = 0; i < n;){
            char cur = s[i];
            int num = cur-'0';
            while(i < n and s[i] == cur){
                freq[s[i]-'0']++;
                i++;
            }
            ans += min(freq[0], freq[1]);
            // if 0, reset 1, if 1, reset 0
            freq[(num+1)%2] = 0;
        }
        return ans;
    }
};
