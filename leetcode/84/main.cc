class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Define: "right" index and "left" index as the first index for a height:
        //    heights[left] < height > heights[right]
        // By this, we can calculate the area: height * (right - left - 1)
        int n = heights.size();
        if(n == 0) return 0;
        int max_area = 0;
        int left, right;
        int top;
        // storing increasing indices: we can know "left" indices by maintaining this stack
        stack<int> stk;
        for(int i = 0; i < n; i++){
            int h = heights[i];
            // if the stack is still empty, we will just push the current index
            // or if the height corresponding to the top index in the stack is < h,
            // push the current index
            // Note: when we push the current index, 
            // it means we still have not find a "right" index
            if(stk.empty() or heights[stk.top()] < h){
                stk.push(i);
            }else if(heights[stk.top()] != h){
                // We find a "right" index: the first index satisfy this relationship:
                // h > heights[right]
                // By this information, we can calculate the area by: h * (right - left - 1)
                while(!stk.empty() and heights[stk.top()] > h){
                    // (left, right) with a rectangle of height rect_h
                    int rect_h = heights[stk.top()];
                    stk.pop();
                    right = i;
                    // Note: heights[left] < ... > heights[right]
                    if(!stk.empty()) left = stk.top();
                    else left = -1;
                    max_area = max(max_area, rect_h * (right - left - 1));
                }
                stk.push(i);
            }else{
                // If heights[stk.top()] == h,
                // we can replace the top index by the latest index:
                // Ex. [1,1,1,4]
                stk.pop();
                stk.push(i);
            }
        }
        // The stack must contain heights
        // because the min height will always stay in the stack
        assert(!stk.empty());
        // Setting each height as the rectangle height and then compute each area
        while(!stk.empty()){
            int rect_h = heights[stk.top()];
            stk.pop();
            if(!stk.empty()) left = stk.top();
            else left = -1;
            // Note: n will be the "right"
            max_area = max(max_area, rect_h * (n - left - 1));
        }
        return max_area;
    }
};
