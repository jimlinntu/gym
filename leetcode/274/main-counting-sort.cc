class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n == 0) return 0;
        // count[i] == # of papers having i citations
        vector<int> count(n+1, 0);
        // Suppress c[i] >= n to n
        for(int i = 0; i < n; i++){
            count[min(c[i], n)]++;
        }
        int sum = 0;
        for(int i = n; i >= 0; i--){
            sum += count[i];
            // sum == # of papers that have at least i citations
            // if sum >= i
            if(sum >= i) return i;
        }
        assert(false);
        return -1;
    }
};
