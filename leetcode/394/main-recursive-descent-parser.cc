ass Solution {
public:
    // Grammar:
    // S -> abcd k[S] abcd k[S]
    // cur is like a input stream pointer
    string parse(string &s, int &cur){
        // Consume characters
        string ans;
        while(cur < s.size()){
            for(; cur < s.size(); cur++){
                if(isalpha(s[cur])) ans.push_back(s[cur]);
                else break;
            }
            if(cur == s.size()) break;
            if(s[cur] == ']') break;
            // get k
            int idx = s.find('[', cur);
            int k = stoi(s.substr(cur, idx-cur));
            // consume [
            cur = idx+1;
            // Recursive descent parser
            string dup = parse(s, cur);
            for(int j = 0; j < k; j++){
                ans += dup;
            }
            assert(s[cur] == ']');
            // consume ]
            cur++;
        }
        return ans;
    }
    string decodeString(string s) {
        int cur = 0;
        return parse(s, cur);
    }
};
