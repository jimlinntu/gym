class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int idx = 0;
        // intervals[idx].end < newInterval.start will not be affected by this interval
        for(; idx < n and intervals[idx][1] < newInterval[0]; idx++){
            ans.push_back(intervals[idx]);
        }

        // the intervals that are affected by this newInterval
        int start = newInterval[0], end = newInterval[1];
        for(; idx < n and intervals[idx][0] <= newInterval[1]; idx++){
            start = min(start, intervals[idx][0]);
            end = max(end, intervals[idx][1]);
        }
        ans.push_back({start, end});
        for(; idx < n; idx++){
            ans.push_back(intervals[idx]);
        }
        return ans;
    }
};
