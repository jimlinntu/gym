class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        
        // Row histogram
        // NB: the last element is a dummy one
        vector<int> values(n+1, 0);
        vector<int> stk;
        values[n] = -1; // this will ensure the max histogram algorithm runs correctly
        int maxArea = 0;
        
        for(int i = 0; i < m; i++){
            // Perform maximum histogram area algorithm
            for(int j = 0; j < n+1; j++){
                // j == n is a dummy element
                if(j < n){
                    if(matrix[i][j] == '0') values[j] = 0; // zero the histogram
                    else values[j]++;
                }
                // if the "right" index is found
                if(stk.empty() or values[stk.back()] < values[j]){
                    stk.push_back(j);
                }else{
                    // update the max rect
                    while(!stk.empty() and values[stk.back()] >= values[j]){
                        int h = values[stk.back()];
                        stk.pop_back();
                        int l = (stk.empty())? (-1):(stk.back());
                        maxArea = max(maxArea, h * (j-l-1));
                    }
                    
                    stk.push_back(j);
                }
            }
            // Clear the stack
            stk.clear();
        }
        return maxArea;
    }
};
