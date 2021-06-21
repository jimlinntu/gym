struct E{
    int start_x;
    int end_x;
    int h;
    bool operator<(const E &r) const{
        if(h < r.h) return true;
        if(h > r.h) return false;
        return true; // does not matter
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> points;
        for(auto &b: buildings){
            int l = b[0], r = b[1], h = b[2];
             // starting points should come first
            points.push_back({l, -h, r}); // record their end times
            points.push_back({r, h, 0});
        }
        sort(points.begin(), points.end());
        // max queue
        priority_queue<E> pq;

        for(auto &p: points){
            int x = p[0], h = p[1], end_x = p[2];
            int cur_h = 0;
            if(!pq.empty()) cur_h = pq.top().h;

            if(h < 0){
                h = -h;
                // the height is greater
                if(h > cur_h){
                    ans.push_back({x, h});
                }
                pq.push({x, end_x, h});
            }else{
                // If the top E is outdated, pop it out
                // Note: This is a lazy popping.
                // Ex. [2, 4, 5], [3, 6, 8]
                // Then when we are at 4, we do not actually pop h == 5 out
                while(!pq.empty() and pq.top().end_x <= x) pq.pop();
                int new_h = 0;
                if(!pq.empty()) new_h = pq.top().h;
                // the height changes and this position have not been added by left edges
                if(new_h < cur_h){
                    ans.push_back({x, new_h});
                }
            }
        }
        return ans;
    }
};
