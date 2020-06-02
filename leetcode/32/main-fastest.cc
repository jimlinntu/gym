class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int max_len = 0;
        stack<int> indices;
        // You can imagine there is a ) at index -1 position
        // i.e. s[-1] = ')'
        indices.push(-1);
        for(int i = 0; i < n; i++){
            if(s[i] == '(') indices.push(i);
            else{
                // if there is a match (i.e. "()"), then we can pop the stack
                // and update the max length by (i - indices.top())
                // (because the string in (indices.top(), i] is a valid parenthese)
                // else if there isn't a match (i.e. "))"), then we can substitute
                // the top of the stack by the latest one
                // To sum up, no matter "()" or "))", we all need to pop the stack
                indices.pop();
                
                // if the stack is empty, it means a "))" occurs
                if(indices.empty()) indices.push(i);
                // a "()" occurs
                else{
                    max_len = max(max_len, i - indices.top());
                }
            }
        }
        return max_len;
    }
};
