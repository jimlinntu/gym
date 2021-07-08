class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int l = 0, r = 0; // [l, r) window
        int j = 0; // the next character (i.e. t[j] to match)
        
        int best_l = -1;
        int min_len = INT_MAX;
        // Each s[i] will be at most visited O(t.size()) times
        // So the complexity is O(s.size() * t.size())
        for(; l < m;){
            // move r until we find the first substring contains t
            while(r < m and j != n){
                if(s[r] == t[j]) j++;
                // keep moving right
                r++;
            }
            // no need to search anymore
            if(j < n) break;
            // find the mid point
            int mid = r-1;
            int jj = (int)n-1;

            // match backward
            while(l <= mid and 0 <= jj){
                if(s[mid] == t[jj]) jj--;
                mid--;
            }

            assert(jj == -1);
            mid = mid+1; // mid will walk one step further
            // [mid, r) is a substring contains t
            // NOTE: [x, r) where x > mid does not contain t
            if(r - mid < min_len){
                best_l = mid;
                min_len = r-mid;
            }

            // move on
            l = mid+1;
            // reset r and j
            j = 0;
            r = l;
        }
        if(min_len == INT_MAX) return "";
        return s.substr(best_l, min_len);
    }
};
