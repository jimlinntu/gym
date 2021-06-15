struct Info {
    string s;
    int start_search_idx;
    int start_remove_idx;
    // (par_l, par_r) == ('(', ')') or (')', '(')
    char par_l;
    char par_r;
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // BFS
        vector<string> ans;
        int n = s.size();
        if(n == 0) return ans;
        // A unified way to solve ...)...)...(...(...
        // Observe that: ...)...)...)
        //               ^^^^         <----- at least remove one )
        //               ^^^^^^^^     <----- at least remove two )s
        //               ^^^^^^^^^^^^ <----- at least remove three )s
        queue<Info> q;
        q.push({s, 0, 0, '(', ')'});
        while(!q.empty()){
            Info info = q.front();
            q.pop();
            int stack = 0;
            // Go right until we meet a redundant ')' (or '(' when reversed)
            // NOTE: in this loop we only handle redundant ')' (par_r)
            string &ss = info.s;
            for(int i = info.start_search_idx; i < ss.size(); i++){
                if(ss[i] == info.par_l) stack++;
                else if(ss[i] == info.par_r) stack--;
                if(stack >= 0) continue;
                // We must at least remove one ')' (par_r) inside this region
                for(int j = info.start_remove_idx; j <= i; j++){
                    if(ss[j] == info.par_r and
                       (j == info.start_remove_idx or ss[j-1] != ss[j])){
                        // NOTE: [0, j) + [j+1, ss.size()) 's length = ss.size()-1
                        // so i, j do not need to change!
                        q.push({ss.substr(0, j) + ss.substr(j+1),
                                i, j, info.par_l, info.par_r});
                    }
                }
                break; // because we want to find the redundant ')' (par_r)
            }

            // stack >= 0 means we have already remove all redundant
            // ')' (actually par_l)
            // Therefore, we should reverse this string and swap '(' and ')'
            if(stack >= 0){
                reverse(ss.begin(), ss.end());
                // if par_l == ')', we know that redundant '(' have been all removed
                if(info.par_l == ')') ans.push_back(ss);
                else{
                    // restart from the end of the original string
                    // so the start of the reversed original string
                    // NOTE: we should swap par_r and par_l
                    q.push({ss, 0, 0, ')', '('});
                }
            }
        }
        return ans;
    }
};
