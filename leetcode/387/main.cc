class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        int n = s.size();
        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0; i < n; i++){
            if(freq[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
