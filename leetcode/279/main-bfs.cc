class Solution {
public:
    int numSquares(int n){
        if(n == 0) return 0;
        queue<pair<int, int>> q;
        q.push(pair<int, int>(n, 0));
        while(true){
            int current = q.front().first;
            int dist = q.front().second;
            q.pop();
            int upper = (int)sqrt(current);
            for(int i = upper; i > 0; i--){
                int next = current - i*i;
                int next_dist = dist+1;
                if(next == 0){
                    return next_dist;
                }else{
                    q.push(pair<int, int>(next, next_dist));
                }
            }
        }
        return -1;
    }
};
