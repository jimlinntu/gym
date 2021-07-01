class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        if(s.size() != t.size()) return false;
        for(char c: s){
            freq[c-'a']++;
        }
        for(char c: t){
            if(--freq[c-'a'] < 0) return false;
        }
        return true;
    }
};
