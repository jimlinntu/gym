class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& inters) {
        // Henry's solution
        // This is like a sweeping line algorithm
        // to check how many conflicts we have
        int n = inters.size();
        vector<pair<int, int>> times;
        for(int i = 0; i < n; i++){
            // Plus 1 because this meeting has started and we need a room
            times.push_back({inters[i][0], 1});
            // Minus 1 because this meeting has ended
            // And we release this room
            times.push_back({inters[i][1], -1});
        }
        sort(times.begin(), times.end());
        int num_rooms_at_this_time = 0;
        int ans = 0;
        for(auto &time: times){
            auto [timestamp, meet_type] = time;
            num_rooms_at_this_time += meet_type;
            ans = max(ans, num_rooms_at_this_time);
        }
        return ans;
    }
};

