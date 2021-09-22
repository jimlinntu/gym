// https://leetcode.com/discuss/interview-question/1079570/bloomberg-technical-phone-screen-swe-new-gra&#8205;&#8205;&#8205;&#8204;&#8205;&#8205;&#8205;&#8204;&#8204;&#8204;&#8205;&#8205;&#8204;&#8204;&#8204;&#8204;&#8204;&#8204;&#8205;d-2021-nyc
class Solution {
public:
    int maxDepth(string s) {
        int count = 0; // simulate a stack
        int n = s.size();
        int depth = 0;
        vector<string> ans;
        string cur_str;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cur_str.clear();
                count++;
                if(count > depth){
                    depth = count;
                    ans.clear(); // no one
                }
            }else if(s[i] == ')'){
                if(count == depth) ans.push_back(cur_str);
                count--; // use a (
                cur_str.clear();
            }else{
                cur_str.push_back(s[i]);
            }
        }
        for(auto &s: ans){
            cout << s << endl;
        }
        return depth;
    }
};
