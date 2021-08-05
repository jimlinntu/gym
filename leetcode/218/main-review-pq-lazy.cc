struct E{
    int x_end; // need to know where is this height
    int h; // the height
    bool operator<(const E &r) const{
        return h < r.h;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v;
        for(int i = 0; i < buildings.size(); i++){
            auto &b = buildings[i];
            int l = b[0], r = b[1], h = b[2];
            // we want this to come first
            // Ex. [1, 2, h=3], [2, 4, h=3]
            v.push_back({l, -h, r}); // NOTE: the highest first
            v.push_back({r, h, -1}); // NOTE: the highest last
        }

        sort(v.begin(), v.end());
        // Max PQ
        priority_queue<E, vector<E>> pq;
        pq.push({-1, 0}); // the ground will ends at +inf

        vector<vector<int>> ans;
        for(int i = 0; i < v.size(); i++){
            int x_start = v[i][0], h = v[i][1], x_end = v[i][2];
            
            if(h < 0){
                h = -h;
                // low to high
                int prev_h = pq.top().h;
                // NOTE: if there are multiple buildings starting from
                //       this x, we will start from the highest
                //       so that the smaller one will not contribute to `ans`
                pq.push({x_end, h});
                int after_h = pq.top().h;

                if(prev_h < after_h) ans.push_back({x_start, after_h});
            }else{
                int prev_h = pq.top().h;
                // remove all the things <= x_start (leave this building)
                // NOTE: there might be multiple building ending at this x
                //       but that's ok, because we will remove all at once
                //       when we first see this position
                //       So other ending at this position will have prev_h == after_h
                while(pq.top().x_end <= x_start
                      and pq.top().x_end != -1) pq.pop();
                int after_h = pq.top().h;

                // high to low
                if(prev_h > after_h) ans.push_back({x_start, after_h});
            }
        }
        // Comment:
        // I think the reason why the building ends are responsible
        // for the prev_h > after_h is because
        // generally, when we "leave" a building, the height will become smaller
        return ans;
    }
};
