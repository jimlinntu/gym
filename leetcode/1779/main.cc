class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ansidx = -1;
        int ansdist = INT_MAX;
        int n = points.size();
        for(int i = 0; i < n; i++){
            if(points[i][0] == x or points[i][1] == y){
                int d = abs(points[i][0] - x) + abs(points[i][1] - y);
                if(d < ansdist){
                    ansidx = i;
                    ansdist = d;
                }
            }
        }
        return ansidx;
    }
};
