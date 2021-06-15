class Solution {
public:
    vector<string> leftans;
    vector<string> ans;

    vector<int> left_stack;
    vector<int> right_stack;

    string left_path;
    string right_path; // NOTE: in reverse order

    void solve_left(string &s, int start, int stack_idx){
        // We have delete ')' that we need to delete
        if(stack_idx >= left_stack.size()){
            int prev_size = left_path.size();
            // add the remaining characters
            if(left_stack.size() > 0)
                left_path += s.substr(start, left_stack.back() - start+1);
            leftans.push_back(left_path);
            left_path.resize(prev_size);
            return;
        }
        int prev_size = left_path.size();
        // Choose a character to delete
        for(int i = start; i <= left_stack[stack_idx]; i++){
            // NOTE: To avoid duplicates, consider this example
            // Ex. ()(()))
            //         ^
            //          ^
            //           ^
            // This will cause duplicates so we only allow
            // D == delete, P == preserve
            // DDD
            // DDP
            // DPP
            // DPD <-- cause duplicates
            if(s[i] == ')'){
                // If there are consecutive ))), we only allow the first one be deleted
                if(i == start or s[i-1] != s[i]){
                    solve_left(s, i+1, stack_idx+1);
                }
            }
            left_path.push_back(s[i]);
        }
        left_path.resize(prev_size);
    }

    void solve_right(string &s, int start, int stack_idx){
        if(stack_idx < 0){
            // add the remaining characters
            int prev_size = right_path.size();
            if(right_stack.size() > 0){
                for(int i = start; i >= right_stack[0]; i--)
                    right_path.push_back(s[i]);
            }
            for(int i = 0; i < leftans.size(); i++){
                ans.push_back(
                    leftans[i] + string(right_path.rbegin(), right_path.rend()));
            }
            right_path.resize(prev_size);
            return;
        }
        // Choose a '(' to delete
        int prev_size = right_path.size();
        int end = right_stack[stack_idx];
        for(int i = start; i >= end; i--){
            if(s[i] == '('){
                // Ex. ((())
                //     PPD
                if(i == start or s[i] != s[i+1]){
                    solve_right(s, i-1, stack_idx-1);
                }
            }
            right_path.push_back(s[i]);
        }
        right_path.resize(prev_size);
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        if(n == 0) return ans;
        vector<int> stack;
        // Intuition:
        // Ex. ? ? ? ? ? ? )
        //                 ^
        // If this is the first redundant one (using greedy), then
        // everything in front of having ')' can be deleted to replace the ')' at the end!
        for(int i = 0; i < n; i++){
            if(s[i] != '(' and s[i] != ')') continue;
            if(!stack.empty() and s[i] == ')' and s[stack.back()] == '('){
                stack.pop_back();
            }else{
                stack.push_back(i);
            }
        }
        if(stack.size() == 0) return {s};

        // left_stack: the indices for )...)...)
        // right_stack: the indices for (...(...(
        for(int idx: stack){
            if(s[idx] == ')') left_stack.push_back(idx);
            else if(s[idx] == '(') right_stack.push_back(idx);
            else assert(false);
        }

        // 1. Solve the left side: )...)...)
        solve_left(s, 0, 0);
        // 2. Append the middle within ) ... (
        //                               ^^^ <---- [mid_left, mid_right)
        int mid_left = 0, mid_right = n;
        if(left_stack.size() > 0) mid_left = left_stack.back()+1;
        if(right_stack.size() > 0) mid_right = right_stack[0];
        // [mid_left, mid_right)
        if(mid_left < mid_right){
            for(int i = 0; i < leftans.size(); i++){
                leftans[i] += s.substr(mid_left, mid_right - mid_left);
            }
        }
        // 3. Solve the right side:
        solve_right(s, n-1, (int)right_stack.size() - 1);
        return ans;
    }
};
