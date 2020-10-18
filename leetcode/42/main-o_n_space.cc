class Solution {
public:
    int left[30000], right[30000];
    int trap(vector<int>& heights) {
        int n = heights.size();
        int amt = 0;
        if(n == 0) return 0;

        left[0] = right[n-1] = 0;
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1], heights[i-1]);
            right[n-i-1] = max(right[n-i], heights[n-i]);
        }
        
        for(int i = 0, bar; i < n; i++){
            bar = min(left[i], right[i]);
            if(bar > heights[i]){
                amt += bar - heights[i];
            }
        }
        return amt;
    }
};
