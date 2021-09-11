class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort by start time
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = intervals.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            if(pq.empty()){
                ans++; // add a meeting room
            }else{
                if(pq.top() <= start){
                    pq.pop();
                }else{
                    ans++;
                }
            }
            pq.push(end);
        }
        return ans;
    }
};
