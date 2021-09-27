class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &l, const vector<int> &r){
            return l[1] < r[1];
        });
        int prev_end = INT_MIN;
        int n = intervals.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            // compatible
            if(prev_end <= start){
                ans++;
                prev_end = end;
            }
        }
        return n-ans;
    }
};
