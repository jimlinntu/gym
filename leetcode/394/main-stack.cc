class Solution {
public:
    int get_expand_start_idx(string &s){
        for(int i = s.size()-1; i >= 1; i--){
            if(s[i-1] == '[') return i;
        }
        assert(false);
        return -1;
    }
    int get_repeat_start_idx(string &s, int endidx){
        for(int i = endidx; i >= 1; i--){
            if(!isdigit(s[i-1])) return i;
        }
        return 0;
    }
    string decodeString(string s) {
        int n = s.size();
        string stk;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(isdigit(c)){
                stk.push_back(c);
            }else if(c == '['){
                stk.push_back(c);
            }else if(c == ']'){
                // pop until we find `num[`
                // Ex. 200[abcde + ]
                int startidx = get_expand_start_idx(stk);
                int repeat_startidx = get_repeat_start_idx(stk, startidx-2);

                string t(stk.begin()+startidx, stk.end());
                int repeat = stoi(string(stk.begin()+repeat_startidx,
                                         stk.begin()+startidx-1));
                // Truncate that region
                stk.resize(repeat_startidx);
                for(int j = 0; j < repeat; j++){
                    stk.insert(stk.end(), t.begin(), t.end());
                }
                
            }else stk.push_back(c);
        }
        return stk;
    }
};
