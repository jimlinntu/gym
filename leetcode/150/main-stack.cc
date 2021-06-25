class Solution {
public:
    pair<int, int> extract_two(stack<int> &stk){
        int x = stk.top();
        stk.pop();
        int y = stk.top();
        stk.pop();
        return {y, x};
    }
    int evalRPN(vector<string>& tokens) {
        int x, y;
        stack<int> stk;
        for(string tok: tokens){
            assert(tok.size() > 0);
            if(tok[0] == '*'){
                tie(x, y) = extract_two(stk);
                stk.push(x * y);
            }else if(tok[0] == '/'){
                tie(x, y) = extract_two(stk);
                stk.push(x / y);
            }else if(tok[0] == '+' and tok.size() == 1){
                tie(x, y) = extract_two(stk);
                stk.push(x + y);
            }else if(tok[0] == '-' and tok.size() == 1){
                tie(x, y) = extract_two(stk);
                stk.push(x - y);
            }else{
                stk.push(stoi(tok));
            }
        }
        assert(stk.size() == 1);
        return stk.top();
    }
};
