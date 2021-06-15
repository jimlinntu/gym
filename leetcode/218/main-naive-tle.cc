class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        // Critical points
        vector<vector<int>> points;

        for(int i = 0; i < n; i++){
            auto &b = buildings[i];
            int left = b[0], right = b[1], h = b[2];
            // [left, right)
            points.push_back({left, h});
            points.push_back({right, 0});
        }

        sort(points.begin(), points.end());
        // For each building, update points inside this region
        for(int i = 0; i < n; i++){
            auto &b = buildings[i];
            int left = b[0], right = b[1], h = b[2];
            // Loop over all points
            for(int j = 0; j < points.size(); j++){
                auto &p = points[j];
                int x = p[0], y = p[1];
                // [left, right)
                if(left <= x and x < right){
                    // update this points height
                    p[1] = max(y, h);
                }
            }
        }
        vector<vector<int>> out_points;
        for(int i = 0; i < points.size(); i++){
            auto &p = points[i];
            int x = p[0], y = p[1];
            // Can be skipped
            if(i > 0 and y == points[i-1][1]) continue;
            out_points.push_back({x, y});
        }
        return out_points;
    }
};
