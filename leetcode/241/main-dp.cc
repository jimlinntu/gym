struct Info{
    int start, end; // [start, end] is a number
};
class Solution {
public:
    vector<Info> preprocess(string &expr){
        int n = expr.size();
        vector<Info> infos;
        for(int i = 0; i < n; i++){
            if(!isdigit(expr[i])) continue;
            int j = i;
            for(; j < n and isdigit(expr[j]); j++){}
            infos.push_back({i, j-1});
            i = j-1;
        }
        return infos;
    }
    
    void combine(vector<int> &left, char op, vector<int> &right,
                 vector<int> &result){
        int num;
        for(int l: left){
            for(int r: right){
                if(op == '+') num = l+r;
                else if(op == '-') num = l-r;
                else if(op == '*') num = l*r;
                else num = l/r;
                result.push_back(num);
            }
        }
    }

    vector<int> diffWaysToCompute(string expression) {
        // dp[i][j] == the possible results from [i, j]
        auto &expr = expression;
        vector<Info> infos = preprocess(expr);
        int n = infos.size(); // # of numbers inside this expression
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        // dp[i][i] == {that number}
        for(int i = 0; i < n; i++){
            string num_str = expr.substr(infos[i].start, infos[i].end - infos[i].start+1);
            int num = stoi(num_str);
            dp[i][i] = {num};
        }

        // dp[i][j] == combine(dp[i][k], op, dp[k+1][j]) for all i <= k <= j-1
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                // Compute dp[i][j]
                for(int k = i; k <= j-1; k++){
                    // The operator is at infos[k].end+1
                    // Ex. 123 * 56
                    //       ^ ^
                    char op = expr[infos[k].end+1];
                    // [i, k] op [k+1][j]
                    combine(dp[i][k], op, dp[k+1][j], dp[i][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};
