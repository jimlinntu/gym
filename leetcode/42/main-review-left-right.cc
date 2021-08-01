class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // left[i] == max(height[0] ~ height[i-1])
        vector<int> left(n), right(n);
        int left_max = INT_MIN;
        int right_max = INT_MIN;
        for(int i = 0; i < n; i++){
            // left to right
            left[i] = left_max;
            left_max = max(left_max, height[i]);
            
            // right to left
            right[n-i-1] = right_max;
            right_max = max(right_max, height[n-i-1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int m = min(left[i], right[i]);
            if(m == INT_MIN) continue;
            if(m > height[i]){
                ans += m-height[i];
            }
        }
        return ans;
    }
};
