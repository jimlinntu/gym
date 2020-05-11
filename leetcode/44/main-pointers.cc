class Solution {
public:
    bool isMatch(string s, string p) {
        // O(mn) but in most cases faster than DP solution
        int n = s.length(), m = p.length();
        int ptr_s = 0, ptr_p = 0;
        int match_til_idx = -1; // pattern can match s[0:match_til_idx] (not including match_til_idx)
        int last_star_idx = -1;
        
        // Key concept: match greedily, only rewind (*Note: this is why this algorithm is O(mn)) to the last '*' char position
        // when we cannot match the current character!
        
        // Try to consume all characters
        while(ptr_s < n){
            if(ptr_p < m && (s[ptr_s] == p[ptr_p] or p[ptr_p] == '?')){
                // try to greedily match p[ptr_p] and s[ptr_s]
                ptr_s++, ptr_p++;
            }else if(ptr_p < m && p[ptr_p] == '*'){
                // Record this position as the saving point, every time we fail at greedy matching,
                // we go back to this place
                last_star_idx = ptr_p;
                match_til_idx = ptr_s; // match s[0:match_til_idx]
                ptr_p++; // Assume this * pattern will expand to the empty string and try to use the next character to match it first
            }
            // if s[ptr_s] cannot be matched by p[ptr_p]
            else if(last_star_idx != -1){
                // rewind the pattern pointer to the last position
                match_til_idx++; // advance match_til_idx
                ptr_s = match_til_idx; // reset ptr_s to match_til_idx
                ptr_p = last_star_idx+1; // rewind
            }else{
                return false; // there is no star before this pattern, this pattern must not match this string!
            }
        }
        
        // Check if the remaining chars are all '*'
        while(ptr_p < m){
            if(p[ptr_p] == '*') ptr_p++;
            else break;
        }
        
        // If after we match all strings, we still have pattern chars left
        return ptr_p == m;
    }
};
