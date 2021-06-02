class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int end = points[0][1];
        int count = 1;

        for(int i = 1; i < n; i++){
            if(points[i][0] <= end){
                end = min(end, points[i][1]);
            }else{
                end = points[i][1];
                count++;
            }
        }
        return count;
    }
};
