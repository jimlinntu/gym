class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stat) {
        int ans = -1;
        int farest = 0;
        priority_queue<int, vector<int>> pq;
        pq.push(startFuel);
        int idx = 0; // station idx
        int n = stat.size();
        while(farest < target and !pq.empty()){
            farest += pq.top();
            pq.pop();
            ans++;
            while(idx < n and stat[idx][0] <= farest){
                pq.push(stat[idx++][1]);
            }
        }
        if(farest >= target) return ans;
        return -1;
    }
};
