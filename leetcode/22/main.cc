
void expand(int i, int len, int left_count, int right_count, 
            string &s, stack<char> &st, vector<string> &ans){
    if(i == len){
        ans.push_back(s);
        return;
    }
    // Idea: we only have two choice: put ( or ) in s[i]
    if(left_count > 0){
        s[i] = '(';
        st.push('(');
        expand(i+1, len, left_count-1, right_count, s, st, ans);
        st.pop();
    }
    
    if(right_count > 0 and !st.empty() and st.top() == '('){
        s[i] = ')';
        st.pop(); // pop a match
        expand(i+1, len, left_count, right_count-1, s, st, ans);
        st.push('('); // restore a ( it has popped out
    }
    return;
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s(2*n, 0);
        vector<string> ans;
        stack<char> st;
        expand(0, 2*n, n, n, s, st, ans);
        return ans;
    }
};
