class Solution {
public:
    // Recursively find the first smallest character of `s`
    // and then put it into `ans`
    void solve(string s, string &ans){
        int n = s.size();
        if(n == 0) return;
        int freq[26] = {0};
        for(char c: s){
            freq[c-'a']++;
        }
        // 0 must be a valid position because s[0~n-1] contain all chars
        int first_char_pos = 0;
        for(int i = 0; i < n; i++){
            if((int)s[i] < (int)s[first_char_pos])
                first_char_pos = i;
            // remove this character
            int remain_cnt = --freq[s[i]-'a'];
            // if this character is exhausted in s[i+1~n-1],
            // then s[i+1~n-1]'s characters do not have enough characters
            // to form a possible result!!!!!! (do not have enough unique characters)
            if(remain_cnt == 0) break;
        }
        string new_s;
        for(int i = first_char_pos+1; i < n; i++){
            // discard s[first_char_pos] because we already have it in our result
            if(s[i] == s[first_char_pos]) continue;
            new_s.push_back(s[i]);
        }
        ans.push_back(s[first_char_pos]);
        solve(new_s, ans);
    }
    string removeDuplicateLetters(string s) {
        string ans;
        solve(s, ans);
        return ans;
    }
};
