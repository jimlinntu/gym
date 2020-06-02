char inverse(char c){
    switch(c){
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
    }
    return '0';
}

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int> stk;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '[') stk.push(i);
            else{
                if(!stk.empty() and s[stk.top()] == inverse(s[i])){
                    stk.pop();
                }else{
                    stk.push(i);
                }
            }
        }
        return stk.empty();
    }
};
