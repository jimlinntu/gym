class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        int n = s.length();
        stack<int> indices;
        indices.push(-1); // push a null index
        for(int i = 0; i < n; i++){
            if(s[i] == '(') indices.push(i);
            else{
                // if the stack is empty, push a new one
                if(indices.top() == -1){
                    indices.push(i);
                }else{
                    // a match occurs
                    if(s[indices.top()] == '('){
                        indices.pop(); // pop the top one
                        // record (indices.top(), i] is a valid parentheses
                        // so the current length is i - indices.top()
                        max_len = max(max_len, i - indices.top());
                    }else{
                        indices.push(i);
                    }
                }
            }
        }
        return max_len;
    }
};
