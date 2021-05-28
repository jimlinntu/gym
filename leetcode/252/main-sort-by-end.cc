using I = vector<int>;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // Sort w.r.t the end times
        sort(intervals.begin(), intervals.end(),
             [](const I &l, const I &r){
            return l[1] < r[1];
        });
        int cur_end = -1;
        for(I &interval: intervals){
            int s = interval[0], e = interval[1];
            if(s < cur_end) return false;
            cur_end = max(cur_end, e);
        }
        return true;
    }
};
