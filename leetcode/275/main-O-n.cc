class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n == 0) return 0;
        int h = 0;
        for(int i = n-1; i >= 0; i--){
            if(c[i] > h) h++;
            else break;
        }
        return h;
    }
};
