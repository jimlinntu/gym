class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        int n = s.size();
        // This is just a dummy operation to trigger
        // the last update
        string ops = "+-*/";
        // Four states:
        // +, -, *, /
        char op = '+';
        int ans = 0;
        int x = 0;
        // We will put the result into `ans`
        // when we are sure that this x can be put in
        for(int i = 0,j; i < n; i++){
            if(s[i] == ' ') continue;
            if(s[i] == '+' or s[i] == '-'){
                ans += x;
                x = 0;
                op = s[i];
            }else if(s[i] == '*' or s[i] == '/'){
                op = s[i];
            }else{
                for(j = i; j < n and isdigit(s[j]); j++){}
                int num = stoi(s.substr(i, j-i));
                // the previous operator is * or /
                // we update this number into x
                if(op == '*'){
                    x *= num;
                }else if(op == '/'){
                    x /= num;
                }else if(op == '-'){
                    x = -num;
                }else if(op == '+'){
                    x = num;
                }
                i = j-1;
            }
        }
        return ans;
    }
};
