struct E{
    int end, inc;
    bool operator>(const E &r) const{
        return end > r.end;
    }
};
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        int n = updates.size();
        for(int i = 0; i < n; i++){
            result[updates[i][0]] += updates[i][2];
            if(updates[i][1]+1 < length) result[updates[i][1]+1] += -updates[i][2];
        }
        int mx = result[0];
        
        for(int i = 1; i < length; i++){
            result[i] += result[i-1];
            mx = max(mx, result[i]);
        }
        // My line sweeping algorithm
        // Observe:
        // the maximum can only appear at these places
        // Case 1: on a start
        // Case 2: on a end
        // Case 3: not being covered by any [start, end, inc]
        //         i)  if updates.size() == 0 -> return 0
        //         ii) else: we can move this point left or right until it is next to one [start, end]
        // Case 4: on the middle of several [start, end]
        //         WLOG, we can move this point until it is on a start or next to an end
        vector<vector<int>> points;
        for(int i = 0; i < n; i++){
            int start = updates[i][0], end = updates[i][1], inc = updates[i][2];
            // start-1, start, end, end-1 are critical points
            if(start > 0) points.push_back({start-1, -1, -1});
            points.push_back({start, end, inc});
            points.push_back({end, -1, -1}); // <--- I think we don't need {end, -1, -1}
            // Because if the maximum occurs at end, it can be moved left until we meet a start or next to end
            if(end+1 < length) points.push_back({end+1, -1, -1});
        }
        sort(points.begin(), points.end());
        priority_queue<E, vector<E>, greater<E>> pq;
        int num_points = points.size();
        int cur = 0;
        int ans = INT_MIN;
        if(num_points == 0) ans = 0;
        for(int i = 0; i < num_points;){
            int x = points[i][0];
            // remove outdated
            while(!pq.empty() and pq.top().end < x){
                cur -= pq.top().inc;
                pq.pop();
            }
            // add new values
            while(i < num_points and points[i][0] == x){
                if(points[i][1] != -1){
                    cur += points[i][2];
                    pq.push({points[i][1], points[i][2]});
                }
                i++;
            }
            ans = max(cur, ans);
        }
        assert(ans == mx);
        return result;
        
    }
};
