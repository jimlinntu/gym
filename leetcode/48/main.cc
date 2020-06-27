class Solution {
public:
    bool inT(char c, unordered_map<char, int> &map_t){
        return map_t.find(c) != map_t.end();
    }
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if(n == 0 or m == 0) return "";
        
        unordered_map<char, int> map_t;
        unordered_map<char, int> window;
        int min_window;
        int x = 0, y = 0;
        int best_x, best_y;

        // Compute string t statistics
        for(int i = 0; i < m; i++){
            map_t[t[i]]++;
        }
        // Move y until we satisfy all t's unique character counts
        for(auto it = map_t.begin(); it != map_t.end(); it++){
            char c = it->first;
            int count = it->second;
            // check if window[c] >= count, if not, keep move forward
            while(y < n and window[c] < count){
                if(inT(s[y], map_t)) window[s[y]]++;
                y++;
            }
            // if window[c] still < count, we cannot find a string covering all t chars
            if(window[c] < count) return "";
        }
        min_window = y-x+1;
        // Move x forward and then move y forward
        while(x < y){
            if(y-x < min_window){
                min_window = y-x;
                best_x = x, best_y = y;
            }
            char c = s[x++];
            if(!inT(c, map_t)) continue; // if it is not a char in t, ignore it
            int remain = (--window[c]); // move x forward, decrement window[c]
            int count = map_t[c];
            if(remain >= count) continue; // if char c still has enough char, keep going
            // if not, we need to move y forward to compensate our character loss
            while(y < n and window[c] < count){
                if(inT(s[y], map_t)) window[s[y]]++;
                y++;
            }
            if(window[c] < count) break;
        }
        return string(s.begin()+best_x, s.begin()+best_y);
    }
};
