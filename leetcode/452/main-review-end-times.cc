class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int> &l, const vector<int> &r) -> bool{
            return l[1] < r[1];
        });
        int ans = 1;
        int n = points.size();
        int lastarrow = points[0][1];
        for(int i = 1; i < n; i++){
            int start = points[i][0], end = points[i][1];
            if(lastarrow < start){
                ans++;
                // must use one arror to blow off 
                // points[i]
                // we will choose as right as possible (choose end)
                // because choosing start has no benefit!
                lastarrow = end;
            }
        }
        return ans;
    }
};
