class Solution {
public:
    int maxDepth(string s) {
        int count = 0; // simulate a stack
        int n = s.size();
        int depth = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                depth = max(depth, ++count);
            }else if(s[i] == ')'){
                count--; // use a (
            }
        }
        return depth;
    }
};
