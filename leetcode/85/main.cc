class Solution {
public:
    int maxHist(vector<int> &values){
        static vector<int> stack;
        int n = values.size();
        int max_area = 0;
        for(int i = 0; i < n; i++){
            // if the stack is empty 
            int val = values[i];
            if(stack.empty() or values[stack.back()] < val){
                stack.push_back(i); // append this index
            }else if(values[stack.back()] == val){
                // We can throw away the old index, for example:
                // 3 2 4 | 4 (when we encounter the next 4,
                // the first 4 can be thrown away)
                stack.pop_back();
                stack.push_back(i);
            }else{
                // the index i will be "right" index
                while(!stack.empty() and values[stack.back()] >= val){
                    int h = values[stack.back()]; // use this as the rect height
                    stack.pop_back();
                    int l;
                    // the previous index is the "left" index
                    if(!stack.empty()) l = stack.back();
                    else l = -1; // the index before the first element
                    max_area = max(max_area, h * (i - l - 1));
                }
                stack.push_back(i);
            }
        }
        // pop the remaining
        while(!stack.empty()){
            int h = values[stack.back()];
            stack.pop_back();
            int l;
            if(!stack.empty()) l = stack.back();
            else l = -1;
            max_area = max(max_area, h * (n - l - 1));
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        
        // Row histogram
        vector<int> values(n, 0);
        int maxArea = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') values[j] = 0; // zero the histogram
                else values[j]++;
            }
            // Find the maximal area with a rectangle lying on this row
            maxArea = max(maxArea, maxHist(values));
        }
        return maxArea;
    }
};
