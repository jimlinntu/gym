class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        vector<int> col(n, 0);
        int max_area = 0;
        for(int i = 0; i < m; i++){
            stack<int> stk;
            stk.push(-1); // boundary
            for(int j = 0; j < n; j++){
                col[j] = (matrix[i][j] == '1')? (col[j]+1):(0);
                // the height that is >= col[j] are useless!!
                // Because everything on the right will have to first 
                // pass through col[j]
                while(stk.top() != -1 and col[stk.top()] >= col[j]){
                    // compute height
                    int h = col[stk.top()];
                    stk.pop();
                    max_area = max(max_area, h * (j - stk.top() - 1));
                }
                stk.push(j);
            }
            // Compute the remaining areas
            while(stk.top() != -1){
                int h = col[stk.top()];
                stk.pop();
                max_area = max(max_area, h * (n - stk.top() - 1));
            }
        }
        return max_area;
    }
};
