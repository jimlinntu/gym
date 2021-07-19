class Solution {
public:
    int shortestDistance(vector<string>& w, string w1, string w2) {
        int n = w.size();
        int idx1 = -1, idx2 = -1;
        int d = n;
        for(int i = 0; i < n; i++){
            if(w[i] == w1){
                // save this index
                idx1 = i;
                // look left
                if(idx2 != -1) d = min(d, i-idx2);
            }else if(w[i] == w2){
                // save this index
                idx2 = i;
                // look left
                if(idx1 != -1) d = min(d, i-idx1);
            }
        }
        return d;
    }
};
