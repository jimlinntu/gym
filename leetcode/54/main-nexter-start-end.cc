struct Nexter{
    int m, n;
    int i, j;
    int row_start, row_end;
    int col_start, col_end;
    int dir;
    // right, down, left, up
    int d[4][2] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};
    Nexter(int mm, int nn){
        m = mm, n = nn;
        reset();
    }
    pair<int, int> get_next(){
        if(row_start > row_end or col_start > col_end){
            reset();
            return {-1, -1};
        }
        if(i == -1 and j == -1){
            i = 0, j = 0;
        }else{
            i = i + d[dir % 4][0], j = j + d[dir % 4][1];
        }

        switch(dir % 4){
            case 0:
                if(j == col_end){
                    dir++, row_start++;
                }
            break;
            case 1:
                if(i == row_end){
                    dir++, col_end--;
                }
            break;
            case 2:
                if(j == col_start){
                    dir++, row_end--;
                }
            break;
            case 3:
                if(i == row_start){
                    dir++, col_start++;
                }
            break;
        }
        return {i, j};
    }
    void reset(){
        i = j = -1; // null position: (-1, -1)
        row_start = 0, row_end = m-1;
        col_start = 0, col_end = n-1;
        dir = 0;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        Nexter nexter(m, n);
        int i, j;
        for(tie(i, j) = nexter.get_next(); i != -1 and j != -1;
                tie(i, j) = nexter.get_next()){
            ans.push_back(matrix[i][j]);
        }
        return ans;
    }
};
