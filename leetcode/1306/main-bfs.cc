class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start] == 0) return true;
        // perform bfs
        vector<bool> visit(n);
        queue<int> q;
        q.push(start);
        visit[start] = true;
        int i, left, right;
        while(!q.empty()){
            // Expand neighbors i+arr[i] and i-arr[i]
            i = q.front();
            q.pop();
            left = i-arr[i], right = i+arr[i];
    
            if(right < n and !visit[right]){
                if(arr[right] == 0) return true;
                visit[right] = true;
                q.push(right);
            }
            if(left >= 0 and !visit[left]){
                if(arr[left] == 0) return true;
                visit[left] = true;
                q.push(left);
            }
        }
        return false;
    }
};
