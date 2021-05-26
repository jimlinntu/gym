class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxA = 0;
        // See my proof within the pdf file
        while(l < r){
            maxA = max(maxA, min(height[l], height[r]) * (r-l));
            if(height[l] > height[r]){
                r--;
            }else if(height[l] < height[r]){
                l++;
            }else{
                l++, r--;
            }
        }
        return maxA;
    }
};
