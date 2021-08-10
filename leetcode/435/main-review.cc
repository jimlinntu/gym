class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Get the most non-overlapping interval as possible
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &l, const vector<int> &r) -> bool{
                return l[1] < r[1]; // sort by its end time
            });
        
        int count = 0;
        int end = INT_MIN;
        // Greedily take an interval if it does not collide
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            // NOTE: [start, end)
            // i.e [1, 2), [2, 3) does not count for overlapping intervals
            if(intervals[i][0] < end) continue;
            // Take this interval
            count++;
            end = intervals[i][1];
        }
        // count is the most non-overlapping intervals we can get
        return n-count;
    }
};
