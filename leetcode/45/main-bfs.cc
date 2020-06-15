class Solution {
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return 0;
        vector<int> dist(n); // dist[i] == distance from 0 to i
        int current, start = 1, end;
        queue<int> q;
        q.push(0); 
        dist[0] = 0;
        // BFS
        while(!q.empty()){
            current = q.front();
            q.pop();
            // add neighbors: i
            end = current+nums[current];
            for(int i = start; i <= end && i < n; i++){
                q.push(i);
                dist[i] = dist[current]+1;
                if(i == n-1) return dist[i];
            }
            // record the new starting point so that we won't revisit same indices
            // or this algorithm will become O(n^2) without this
            start = (start < (end+1))?(end+1):(start);
        }
        return -1; // it should not happen
    }
};
