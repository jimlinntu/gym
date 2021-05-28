using I = vector<int>;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // Sort w.r.t the start times
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            // If this is not compatible with the previous one
            // we break
            if(intervals[i][0] < intervals[i-1][1]) return false;
        }
        
        return true;
    }
};
