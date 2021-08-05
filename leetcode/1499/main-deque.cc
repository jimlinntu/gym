struct E{
    int x;
    int y_plus_x;
};
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        deque<E> dq;
        int r = 0;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int x = points[i][0], y = points[i][1];
            // If the x in front is this x, then pop it out
            if(!dq.empty() and dq.front().x == x){
                dq.pop_front();
            }
            // Go as right as possible
            r = max(r, i+1); // excluding itself
            while(r < n and points[r][0] <= x+k){
                // add (x, y+x)
                E e = {points[r][0], points[r][0]+ points[r][1]};
                r++;
                // 
                while(!dq.empty() and dq.back().y_plus_x <= e.y_plus_x){
                    // if this y+x >= than the previous one
                    // the thing in front of it is useless!
                    // because they are older and smaller
                    // => pop it
                    dq.pop_back();
                }
                dq.push_back(e);
            }
            // Ex. (1, 1) (1000, 2), (1001, 3) and k = 2
            //     ^^^^^^ <-- this one does not have a xj s.t. xj-xi <= k == 2
            if(dq.empty()) continue;
            int max_y_plus_x = dq.front().y_plus_x;
            //    yj + yi + xj - xi
            // =  (yi-xi) + yj + xj
            ans = max(ans, max_y_plus_x + y-x);
        }
        return ans;
    }
};
