class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        // the boundaries: [left, right)
        vector<int> left(n, -1), right(n, n+1), height(n, 0);
        int max_area = 0;
        int cur_left, cur_right;
        for(int i = 0; i < m; i++){
            // cur_left: inclusive, cur_right: exclusive
            cur_left = 0, cur_right = n;
            // Update three arrays within a single loop to speed up
            for(int j = 0; j < n; j++){
                // update height
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0; // reinitial the height
                // update the left boundaries:
                // we should take max because only by this boundary can it form a rectangle
                if(matrix[i][j] == '1'){
                    left[j] = max(left[j], cur_left);
                }else{
                    // Ex:
                    // 0 1 0 1 1
                    // 0 1 1 1 1
                    //     ^
                    //     j
                    // left[j] == -1
                    // left[j] should be updated to index 2
                    // because max(left[j], cur_left) is called
                    // we must make left[j] a number smaller than cur_left
                    // Therefore we choose -1 here.
                    left[j] = -1;
                    cur_left = j+1; // must be the next or after
                }
                // update the right boundaries:
                int k = n-j-1;
                if(matrix[i][k] == '1'){
                    right[k] = min(right[k], cur_right);
                }else{
                    // The concept is the same as left[j] = -1;
                    right[k] = n+1;
                    cur_right = k; // must be <= k
                }
            }
            // update the max area by [left, right) * height
            for(int j = 0; j < n; j++){
                max_area = max(max_area, (right[j] - left[j]) * height[j]);
            }
        }
        return max_area;
    }
};
