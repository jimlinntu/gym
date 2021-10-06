class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // if a -> b (a trust b)
        // a is not a town judge
        // b can be a possible candidate
        // * -> j has n-1 links
        // other people only at most have n-2 links
        vector<int> in(n+1, 0), out(n+1, 0);
        for(int i = 0; i < trust.size(); i++){
            int a = trust[i][0], b = trust[i][1];
            in[b]++;
            out[a]++;
        }
        for(int i = 1; i <= n; i++){
            if(in[i] == n-1 and out[i] == 0) return i;
        }
        return -1;
    }
};
