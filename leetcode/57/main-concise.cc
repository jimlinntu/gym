using Interval = vector<int>;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<Interval> ans;
        int n = intervals.size();
        if(n == 0) return {newInterval};
        int i = 0;
        // Add all intervals in front of newInterval
        for(; i < n and intervals[i][1] < newInterval[0]; i++){
            ans.push_back(intervals[i]);
        }
        // Merge newInterval as far right as possible
        for(; i < n and intervals[i][0] <= newInterval[1]; i++){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
        }
        ans.push_back(newInterval);
        // merge things after the original newInterval
        for(; i < n; i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
