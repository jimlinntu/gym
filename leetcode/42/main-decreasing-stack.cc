class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk; // a decreasing stack
        int idx = 0, amt = 0;
        while(idx < n){
            if(stk.empty() or heights[idx] <= heights[stk.top()]){
                stk.push(idx++);
            }else{
                // Note: we will keep poping heights from the stack
                //       until this height can form a decreasing stack
                int bottom = heights[stk.top()];
                stk.pop();
                // if there is no left index, our left side cannot trap water!
                if(stk.empty()) continue;
                int left = stk.top();
                int right = idx;
                // amt += (width * water height)
                amt += (right - left - 1) * (min(heights[left], heights[right])-bottom);
            }
        }
        return amt;
    }
};
