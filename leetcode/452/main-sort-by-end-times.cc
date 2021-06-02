class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort by end times
        sort(points.begin(), points.end(),
             [](const vector<int> &l, const vector<int> &r) -> bool{
            return l[1] < r[1];
        });

        int n = points.size();
        if(n == 0) return 0;
        int end = points[0][1];
        int count = 1;

        for(int i = 1; i < n; i++){
            if(points[i][0] > end){
                // Initialize a new arrow
                end = points[i][1];
                count++;
            }
        }
        return count;
    }
};
