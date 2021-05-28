class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& inters) {
        int n = inters.size();
        if(n == 0) return 0;
        int ans = 0;
        sort(inters.begin(), inters.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            int s = inters[i][0], e = inters[i][1];
            if(!pq.empty() and s >= pq.top()){
                // [s, e] can be put into the meeting rooms
                // we currently have
                pq.pop();
                pq.push(e);
            }else{
                // Open an new meeting room
                pq.push(e);
                ans++;
            }
        }
        return ans;
    }
};
