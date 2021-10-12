class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Intuition:
        // compute it row by row
        // the
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        vector<int> col(n, 0);
        int max_area = 0;
        for(int i = 0; i < m; i++){
            // Increasing stack: stk = {i, j, k ...}
            // col[i] < col[j] < col[k] ...
            stack<int> stk;
            // stk = {idx = 1}
            for(int j = 0; j < n; j++){
                col[j] = (matrix[i][j] == '1')?(col[j]+1):(0);
                // Compute the largest rectangle on the left!
                while(!stk.empty() and col[stk.top()] >= col[j]){
                    // pop it and compute the area
                    int h = col[stk.top()];
                    stk.pop();
                    max_area = max(max_area,
                                  h * (j - ((stk.empty())?(-1):stk.top()) - 1));
                }
                stk.push(j);
            }
            while(!stk.empty()){
                int h = col[stk.top()];
                stk.pop();
                max_area = max(max_area, h * (n-1-((stk.empty())?(-1):stk.top())));
            }
        }
        return max_area;
    }
};
