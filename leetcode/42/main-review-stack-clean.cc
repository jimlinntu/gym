class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk; // an decreasing stack (storing only indices)
        int ans = 0;
        for(int i = 0; i < n; i++){
            // Ex. Special case:
            // 6 3 3 1 4
            // Notice that there are two 3s
            // If we don't push the second 3
            // i.e.
            // 6 3 3 1 4
            //     x
            // Then when computing the water we can trap at 1
            // we will calculate the wrong amount!
            while(!stk.empty() and height[stk.top()] < height[i]){
                // trap water
                int idx = stk.top();
                stk.pop();

                if(!stk.empty())
                    ans += (i-stk.top()-1) * \
                            (min(height[stk.top()], height[i])-height[idx]);
            }
            stk.push(i);
        }
        return ans;
    }
};
