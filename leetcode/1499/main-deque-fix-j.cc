struct E{
    int x;
    int y_minus_x;
};
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        // (x, y-x)
        deque<E> dq;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            auto &p = points[i];
            int x = p[0], y = p[1];
            while(!dq.empty() and dq.front().x < x-k){
                dq.pop_front();
            }

            if(!dq.empty()){
                // yj + yi + xj - xi
                // (yj + xj) + (yi - xi)
                ans = max(ans, x + y + dq.front().y_minus_x);
            }
            // Add this one
            while(!dq.empty() and dq.back().y_minus_x <= y-x){
                // if the y-x on the back is <= current y-x
                // This y-x on the back is totally useless!
                // Because for every j behind, it will also rather choose the current y-x
                dq.pop_back();
            }
            dq.push_back({x, y-x});
        }
        return ans;
    }
};
