class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort by start times
        sort(points.begin(), points.end());
        // https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/112047/Super-strict-and-detailed-proved-Greedy-algorithm!!!
        int ans = 1;
        int arrow_end = points[0][1];
        int n = points.size();
        for(int i = 1; i < n; i++){
            int start = points[i][0], end = points[i][1];
            if(arrow_end < start){
                ans++;
                // must use a new arrow
                arrow_end = end;
            }else{
                // can reuse the previous arrow
                // but the range it can move will be restricted
                // The reasoning here is
                // Since we have to blow off the first balloon anyway,
                // we want to maximize the number of balloon that arrow can blow!
                arrow_end = min(arrow_end, end);
            }
        }
        return ans;
    }
};
