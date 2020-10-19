class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if(n < 3) return 0; // To trap the water, we need at least three heights
        int left = 0, right = n-1;
        int maxleft = 0, maxright = 0;
        int amt = 0;
        
        // Note: Throughout out the loop, these properties must hold
        // 1. if heights[left] <= heights[right],
        //    for every i <= left, heights[i] <= heights[right]
        // 2. if heights[left] > heights[right],
        //    for every j >= right, heights[left] > heights[j]
        // ---------------------------------------
        // Intuitively, you might think that you must know truemaxleft, truemaxright
        // in order to compute (min(truemaxleft, truemaxright) - height)
        // However, by the properties we maintain during the course of the procedure
        // it can be show that we actually do not need to know the truemaxleft and truemaxright.
        // ---------------------------------------
        // When we encounter a heights[left] <= heights[right]
        // Due to the property 1., we know:
        // min(truemaxleft, truemaxright) = min(maxleft <= heights[right], truemaxright >= heights[right])
        // Thus, we do NOT need to know the truemaxright!
        while(left < right){
            // Property 1.
            if(heights[left] <= heights[right]){
                if(heights[left] > maxleft) maxleft = heights[left];
                else amt += maxleft - heights[left];
                left++;
            }
            // Property 2.
            else{
                if(heights[right] > maxright) maxright = heights[right];
                else amt += maxright - heights[right];
                right--;
            }
        }
        return amt;
    }
};
