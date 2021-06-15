class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> points;

        for(int i = 0; i < n; i++){
            auto &b = buildings[i];
            int left = b[0], right = b[1], h = b[2];
            // To deal with 3 edge cases:
            // Ex1. starts are overlapped: [1, -3], [1, -2]
            // Ex2. ends are overlapped:   [3, 2], [3, 3]
            // Ex3. start and end are overlapped: [2, -2], [2, 1]
            points.push_back({left, -h});
            points.push_back({right, h});
        }
        sort(points.begin(), points.end());
        int m = points.size();
        // A priority_queue (a max PQ)
        multiset<int, greater<int>> active_heights; // the heights we have now
        // Follow Tushar's algorithm
        // https://www.youtube.com/watch?v=GSBLe8cKu0s&ab_channel=TusharRoy-CodingMadeSimple
        active_heights.insert(0); // ground is equal to 0
        vector<vector<int>> out_points;
        for(int i = 0; i < m; i++){
            auto &p = points[i];
            int x = p[0], h = p[1];
            int max_h = *active_heights.begin();
            if(h < 0){
                // start
                h = -h;
                if(h > max_h){
                    out_points.push_back({x, h});
                }
                active_heights.insert(h);
            }else if(h > 0){
                // end
                // NOTE: .erase(h) will remove all elements == h
                active_heights.erase(active_heights.find(h));
                int new_max_h = *active_heights.begin();
                if(new_max_h < max_h){
                    out_points.push_back({x, new_max_h});
                }
            }else assert(false);
        }
        return out_points;
    }
};
