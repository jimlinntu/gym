class Solution {
public:
    unordered_map<char, string> map;
    unordered_set<string> seen;
    bool solve(string &pattern, int pstart,
               string &s, int sstart){
        if(pstart >= pattern.size()){
            // if there are remaining chars, return false
            return sstart >= s.size();
        }
        // if this character has appeared before
        // match them
        char c = pattern[pstart];
        if(map.count(c)){
            string &target = map[c];
            int remain_len = s.size() - sstart;
            // no enough chars to consider
            if(target.length() > remain_len) return false;
            // compare them
            for(int i = 0; i < target.length(); i++){
                if(target[i] != s[sstart+i]) return false;
            }
            // Keep searching
            return solve(pattern, pstart+1, s, sstart+target.length());;
        }
        // Try all possible ones
        for(int i = sstart; i < s.size(); i++){
            // [sstart, i]
            int len = i-sstart+1;
            string part = s.substr(sstart, len);
            // if this part is already seen, we keep it
            if(seen.count(part)) continue;
            map[c] = part;
            seen.insert(part);
            // find a possible way, directly return
            if(solve(pattern, pstart+1, s, i+1)) return true;
            seen.erase(part); 
        }
        // the reason why we can put map.erase(c)
        // is because map[c] is being overwritten in the loop body
        map.erase(c);
        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        return solve(pattern, 0, s, 0);
    }
};
