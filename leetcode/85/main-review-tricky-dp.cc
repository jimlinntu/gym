class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        // left[i] == the left boundary for i
        //            h[j] >= h[i] where left[i] <= j <= i
        vector<int> left(n, -1), right(n, n);
        vector<int> cols(n, 0);
        int max_area = 0;
        for(int i = 0; i < m; i++){
            int cur_left = -1, cur_right = n;

            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1' and (j == 0 or matrix[i][j-1] == '0'))
                    cur_left = j;

                if(matrix[i][j] == '1'){
                    left[j] = max(left[j], cur_left);
                }else left[j] = -1;
            }
            for(int j = n-1; j >= 0; j--){
                if(matrix[i][j] == '1' and (j == n-1 or matrix[i][j+1] == '0'))
                    cur_right = j;
                
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j], cur_right);
                }else right[j] = n;
            }
            // Compute areas
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    int h = ++cols[j];
                    max_area = max(max_area,
                        h * (right[j] - left[j] + 1));
                }else{
                    cols[j] = 0;
                }
            }
        }
        return max_area;
    }
};
