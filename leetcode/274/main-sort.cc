class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n == 0) return 0;
        // Solving the largest square which bottom left corner is at (0, 0)
        sort(c.begin(), c.end(), greater<int>());
        int h = 0;
        for(int i = 0; i < n; i++){
            if(c[i] > h) h++;
            else break;
        }
        return h;
    }
};
