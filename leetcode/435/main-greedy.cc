class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort according to their end times
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int> &l, const vector<int> &r){
            return l[1] < r[1];
        });
        // See:
        // https://www.youtube.com/watch?v=2P-yW7LQr08&ab_channel=MITOpenCourseWare
        // 1. Course Overview, Interval Scheduling for more info
        int n = intervals.size();
        int cur_end = INT_MIN;
        int max_nonoverlap = 0;
        for(int i = 0; i < n; i++){
            if(intervals[i][0] >= cur_end){
                // update the end time
                cur_end = intervals[i][1];
                max_nonoverlap++;
            }
        }
        return n-max_nonoverlap;
    }
};
