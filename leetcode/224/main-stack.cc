class Solution {
public:
    bool is_plus_minus(string &s){
        return s.size() == 1 and (s[0] == '+' or s[0] == '-');
    }

    bool is_num(string &s){
        return s.size() >= 2 or isdigit(s[0]);
    }

    int calculate(string s) {
        int n = s.size();
        stack<string> stk;

        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == ' ') continue;

            if(c == '+' or c == '-'){
                // Combine multiple +/- into one
                if(!stk.empty() and is_plus_minus(stk.top())){
                    // ++ or --
                    if(stk.top()[0] == c){
                        stk.pop();
                        stk.push(string(1, '+'));
                    }else{
                        // +- or -+
                        stk.pop();
                        stk.push(string(1, '-'));
                    }
                }else stk.push(string(1, c)); // the first time +/- occurs
            }else if(c == '('){
                stk.push(string(1, c));
            }else if(c == ')'){
                // Pop until we meet ( and then if there are +/- in front of (,
                // we will combine it into this number
                // Ex. +--+-+--(13)
                assert(!stk.empty());
                int num = stoi(stk.top());
                stk.pop(); // pop the number
                assert(stk.top() == "(");
                stk.pop(); // pop the left parenthesis
                // pop +/- if there is any
                if(!stk.empty() and is_plus_minus(stk.top())){
                    if(stk.top()[0] == '+') num = +num;
                    else num = -num;

                    stk.pop();
                }
                // Check if there is a number in front of this num
                // else push this number in
                // Ex. (15 + (17))
                if(!stk.empty() and is_num(stk.top())){
                    int top_num = stoi(stk.top());
                    stk.pop();
                    top_num += num;
                    stk.push(to_string(top_num));
                }else stk.push(to_string(num));
            }else if(isdigit(c)){
                // Find the integer literal
                int j = i;
                for(; j < n and isdigit(s[j]); j++){}
                int num = stoi(s.substr(i, j-i));

                // Put +/- in front into this number
                if(!stk.empty() and is_plus_minus(stk.top())){
                    if(stk.top()[0] == '+') num = +num;
                    else num = -num;
                    stk.pop();
                }

                // Add this number to the previous number
                if(!stk.empty() and is_num(stk.top())){
                    int top_num = stoi(stk.top());
                    stk.pop();
                    top_num += num;
                    // push the new number
                    stk.push(to_string(top_num));
                }else stk.push(to_string(num));

                i = j-1; // move next
            }
        }

        return stoi(stk.top());
    }
};
