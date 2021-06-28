struct Indexer {
    int x, y;
    int accX, accY;
    int stepX, stepY;
    int d; // right, down, left, up
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    Indexer(int n):x(0), y(-1), d(0){
        accX = 0;
        accY = 0;
        stepX = n;
        stepY = n-1;
    }

    pair<int, int> next(){
        int dx = dir[d][0], dy = dir[d][1];
        x += dx, y += dy;

        if(d % 2 == 0) accX++;
        else accY++;

        if(accX == stepX){
            accX = 0; // reset
            stepX--;
            d = (d+1) % 4;
        }else if(accY == stepY){
            accY = 0; // reset
            stepY--;
            d = (d+1) % 4;
        }
        return {x, y};
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int nn = n * n;
        Indexer indexer(n);
        pair<int, int> idx = indexer.next();
        for(int i = 0; i < nn; i++, idx = indexer.next()){
            m[idx.first][idx.second] = i+1;
        }
        return m;
    }
};
