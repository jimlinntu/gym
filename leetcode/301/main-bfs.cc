class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // BFS
        vector<string> ans;
        int n = s.size();
        if(n == 0) return ans;
        // q.front() == (string, the starting index)
        queue<pair<string, int>> q;
        q.push({s, 0});
        while(!q.empty() and ans.empty()){
            for(int i = q.size()-1; i >= 0; i--){
                auto p = q.front();
                q.pop();
                if(is_valid(p.first)) ans.push_back(p.first);
                else{
                    // Choose a '(' or ')' to delete
                    string &ss = p.first;
                    for(int j = p.second; j < ss.size(); j++){
                        if(ss[j] != '(' and ss[j] != ')') continue;
                        // only choose the first one
                        if(j == p.second or ss[j-1] != ss[j]){
                            // [0, j) + [j+1, ss.size())
                            q.push({ss.substr(0, j) + ss.substr(j+1),
                                   j});
                        }
                    }
                }
            }
        }
        return ans;
    }

    bool is_valid(string &s){
        int count = 0;
        for(char c: s){
            if(c == '(') count++; // put it into the stack
            else if(c == ')'){
                // if there is still ( in the stack
                if(count > 0) count--;
                else return false; // ) will be in the stack
            }
        }
        return count == 0;
    }
};
