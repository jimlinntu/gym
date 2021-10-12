class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        int i = 0;
        vector<vector<int>> ans;
        // | |
        //     | |
        // Every thing before this newInterval
        for(; i < n and intervals[i][1] < start; i++){
            ans.push_back(intervals[i]);
        }
        // Merge
        //                   
        //   |              |
        for(; i < n and intervals[i][0] <= end; i++){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
        }
        ans.push_back({start, end});
        for(; i < n; i++){
            ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};
