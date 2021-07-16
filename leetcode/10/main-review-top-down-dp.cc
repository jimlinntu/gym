struct H {
    size_t operator()(const pair<int, int> &p) const{
        return (p.first << 1) ^ p.second;
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, bool, H> map;
    bool match(string &s, int send, string &p, int pend){
        if(send == 0 and pend == 0) return true;
        // running out of pattern but still have text => false
        if(pend == 0) return false;
        
        if(map.find({send, pend}) != map.end())
            return map[{send, pend}];
        // NOTE: send might be 0!!!!
        bool is_wild = p[pend-1] == '*';
        bool ret = false;
        if(is_wild){
            if(send > 0 and (p[pend-2] == '.' or s[send-1] == p[pend-2])){
                // Case 1: match and step back
                // Case 2: match and stay
                // Case 3: not match
                ret = match(s, send-1, p, pend-2) or
                       match(s, send-1, p, pend) or
                       match(s, send, p, pend-2);
            }
            // Case 1: not match
            else ret = match(s, send, p, pend-2);
        }else{
            if(send > 0 and (p[pend-1] == '.' or s[send-1] == p[pend-1]))
                ret = match(s, send-1, p, pend-1);
            else ret = false; // no way to match
        }
        map[{send, pend}] = ret;
        return ret;
    }
    bool isMatch(string s, string p) {
        return match(s, s.size(), p, p.size());
    }
};
