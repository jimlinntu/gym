class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n-1;
        // Notice that: the numbers of L shape are sorted!
        // That is where we can take advantage
        // Complexity: O(m+n) because we can at most delete m rows or n cols
        while(row < m and col >= 0){
            int top_right = matrix[row][col];
            if(top_right == target) return true;
            if(top_right > target) col--;
            else row++;
        }
        return false;
    }
};
