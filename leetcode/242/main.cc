class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length(), n = t.length();
        if(m != n) return false;
        vector<int> holes(26, 0);
        for(int i = 0; i < m; i++){
            holes[s[i]-'a']--; // dig holes
        }
        for(int i = 0; i < m; i++){
            // fill up the hole
            // if there exists a character out of one hole, we are sure they are not anagrams
            if((++holes[t[i]-'a']) > 0) return false;
        }
        return true;
    }
};
