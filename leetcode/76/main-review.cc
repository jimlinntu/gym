class Solution {
public:
    string minWindow(string s, string t) {
        // # of alphabets (w/o duplicates) in t
        // (or # of contraints we need to meet)
        int count = 0;
        unordered_map<char, int> freq;

        for(char c: t){
            if(freq[c]++ == 0) count++;
        }
        // window information: [i, r) for s
        int win_count = 0;
        unordered_map<char, int> win_freq;
        // answer related
        int min_len = INT_MAX;
        int best_i = -1;
        
        int n = s.size();
        int r = 0;
        // For every s[i], we find the minimum window substring that satisfy
        // win_count == count
        for(int i = 0; i < n; i++){

            while(win_count != count and r < n){
                // add this character
                // if we have enough characters for this one
                // we increment the counter
                if(++win_freq[s[r]] == freq[s[r]])
                    win_count++;
                r++; // move right
            }

            if(win_count != count){
                // running out of characters
                assert(r == n);
                break;
            }

            int win_len = r - i;
            if(win_len < min_len){
                min_len = win_len;
                best_i = i;
            }
            
            // leaving this s[i]
            // if we do not have enough characters for this one
            // we will decrement win_count
            if(--win_freq[s[i]] < freq[s[i]])
                win_count--;
        }

        if(min_len == INT_MAX) return "";
        return s.substr(best_i, min_len);
    }
};
