class Solution {
public:
    bool is_num(string &expr, int start, int end){
        if(start >= end) return false;
        for(int i = start; i < end; i++){
            if(!isdigit(expr[i])) return false;
        }
        return true;
    }

    vector<int> solve(string &expr, int start, int end){
        if(start >= end) return {false, -1}; // invalid split, this is empty
        // Base case:
        // Ex. (1)
        if(is_num(expr, start, end)) return {stoi(expr.substr(start, end-start))};

        vector<int> result;
        for(int i = start; i < end-2; i++){
            // [start, i] op [i+2, end)
            // Ex. 1 * 2
            //       ^ invalid split point
            if(!isdigit(expr[i])) continue;
            // Ex. 123
            //      ^ is invalid
            if(isdigit(expr[i+1])) continue;
            // 123 * 456
            //     ^ op
            char op = expr[i+1];
            vector<int> left = solve(expr, start, i+1);
            vector<int> right = solve(expr, i+2, end);
            int comb;
            for(int l: left){
                for(int r: right){
                    if(op == '+') comb = l + r;
                    else if(op == '-') comb = l - r;
                    else if(op == '*') comb = l * r;
                    else comb = l / r;
                    result.push_back(comb);
                }
            }
        }
        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression, 0, expression.size());
    }
};
