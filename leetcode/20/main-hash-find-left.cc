class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = \
            {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> stk;
        for(char c: s){
            // left
            if(map.find(c) == map.end()){
                stk.push(c);
            }else{
                char left = map[c];
                // do not find a (left, right) pair
                if(stk.empty() or stk.top() != left) return false;
                // find a (left, right) pair, pop it out
                stk.pop();
            }
        }

        return stk.empty();
    }
};
