struct Nexter{
    int m, n;
    int i, j;
    int num_step[2];
    int dir;
    int acc_step; // accumulated step of the current direction
    // right, down, left, up
    int d[4][2] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};
    Nexter(int mm, int nn){
        m = mm, n = nn;
        reset();
    }
    pair<int, int> get_next(){
        // When we have no where to walk anymore, go back to (0, -1)
        if(num_step[dir % 2] == 0){
            reset();
            return {0, -1};
        }
        i = i + d[dir % 4][0], j = j + d[dir % 4][1];
        acc_step++;
        // The step reach num_step[dir % 2], we must change the direction
        if(acc_step == num_step[dir % 2]){
            num_step[dir % 2]--; // Decrease the number of steps
            dir++;
            acc_step = 0;
        }
        return {i, j};
    }
    void reset(){
        i = 0, j = -1; // null position: (0, -1)
        num_step[0] = n, num_step[1] = m-1;
        dir = 0;
        acc_step = 0;
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
        for(tie(i, j) = nexter.get_next(); j != -1;
                tie(i, j) = nexter.get_next()){
            ans.push_back(matrix[i][j]);
        }
        return ans;
    }
};
