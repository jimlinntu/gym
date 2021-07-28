class Solution {
public:
    int candy(vector<int>& r) {
        // Forward backward DP
        int n = r.size();
        vector<int> fdp(n, 1); // assign 1 candy per child
        vector<int> bdp(n, 1); // assign 1 candy per child
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(r[i-1] < r[i]) fdp[i] = fdp[i-1]+1;
        }
        for(int i = n-2; i >= 0; i--){
            if(r[i] > r[i+1]) bdp[i] = bdp[i+1]+1;
        }
        for(int i = 0; i < n; i++){
            ans += max(fdp[i], bdp[i]);
        }
        return ans;
    }
};
