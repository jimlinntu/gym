class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int nn = n * n;
        int d = 0;
        int num = 0;
        int x = 0, y = -1;
        int stepX = n, stepY = n-1;

        for(; num < nn; d = (d+1) % 4){
            if(d % 2 == 0){
                for(int i = 0; i < stepX; i++){
                    y = y + dir[d][1];
                    m[x][y] = ++num;
                }
                // the next time we go horizontal we will have one less step
                stepX--;
            }else{
                for(int i = 0; i < stepY; i++){
                    x = x + dir[d][0];
                    m[x][y] = ++num;
                }
                stepY--;
            }
        }
        return m;
    }
};
