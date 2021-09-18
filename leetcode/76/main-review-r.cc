class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int tfreq[256] = {0};
        int t_cnt = 0;
        for(char c: t){
            if(tfreq[c]++ == 0) t_cnt++; // unique
        }
        int win_cnt = 0;
        int winfreq[256] = {0};
        int best_l = -1, best_r = -1;
        // Intuition:
        // this substring must end at some character (position)
        // so we just loop through all ending positions
        // BBBBBADBCABC
        //         ^ ^
        int l = 0;
        for(int r = 0; r < m; r++){
            // add this char
            // if we have enough character of that!
            if(++winfreq[s[r]] == tfreq[s[r]]) win_cnt++;
            // shrink left as close as possible
            // shrink only if we have enough of that character
            while(l <= r and win_cnt == t_cnt and winfreq[s[l]] > tfreq[s[l]]){
                // move right, remove s[l] from the window
                winfreq[s[l]]--;
                l++;
            }
            // if this window has not contain enough win_cnt, continue
            if(win_cnt < t_cnt) continue;

            if(best_l == -1){
                best_l = l, best_r = r;
            }else if(r-l+1 < best_r-best_l+1){
                best_l = l, best_r = r;
            }
        }
        if(best_l == -1) return "";
        return s.substr(best_l, best_r-best_l+1);
    }
};
