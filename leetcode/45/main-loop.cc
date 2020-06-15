class Solution {
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return 0;
        vector<int> dist(n); // dist[i] == distance from 0 to i
        int start = 1, end;
        // Inspired by BFS
        for(int i = 0; i < n; i++){
            end = i+nums[i]+1;
            for(int j = start; j < end && j < n; j++){
                dist[j] = dist[i]+1; // update dist[j]
                if(j == n-1) return dist[j];
            }
            start = (start < end)?(end):(start);
        }
        return -1;
    }
};
