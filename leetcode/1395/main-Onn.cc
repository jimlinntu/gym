class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int s = 0;
        for(int i = 0; i < n; i++){
            int left = 0, right = 0;
            // Compute left
            for(int j = 0; j < i; j++){
                if(r[j] < r[i]) left++;
            }
            // Compute right
            for(int j = i+1; j < n; j++){
                if(r[i] < r[j]) right++;
            }
            // a < b < c or a > b > c
            s += left * right + (i - left) * (n - (i+1) - right) ;
        }
        return s;
    }
};
