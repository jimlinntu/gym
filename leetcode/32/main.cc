class Solution {
public:
    int longestValidParentheses(string s) {
        char c;
        stack<int> indices;
        vector<int> backtrace(s.length(), -1); // point to null
        int max_len = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(!indices.empty()){
                int top = indices.top();
                // if there is a match
                if(s[top] == '(' and s[i] == ')'){
                    indices.pop();
                    // concatenate previous match
                    if((top - 1) > 0 and backtrace[top-1] != -1){
                        backtrace[i] = backtrace[top-1];
                        max_len = max(max_len, i - backtrace[i] + 1);
                    }else{
                        // record [top, i] as a match
                        backtrace[i] = top;
                        max_len = max(max_len, i - top + 1);
                    }
                }else{
                    indices.push(i);
                }
            }else{
                indices.push(i);
            }
        }
        return max_len;
    }
};
