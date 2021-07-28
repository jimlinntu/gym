class Solution {
public:
    int compute(int up, int down){
        // the latter part is computing the peak's candy
        return (up+1)*up/2+(down+1)*down/2+(max(up, down)+1);
    }
    int candy(vector<int>& r) {
        int n = r.size();
        if(n == 1) return 1;
        
        // Note: up and down does not count the peak!!!!
        int up = 0;
        int down = 0;

        int ans = 0;
        int old_delta = 0;
        int new_delta;
        // edge of (i-1, i): r[i]-r[i-1]
        for(int i = 1; i < n; i++){
            int new_delta = r[i]-r[i-1];
            // Whenever we reach delta == 0
            // we will know something
            // NOTE: this solution is extremly tricky
            //       That's why I split out into several parts
            if(new_delta == 0){
                if(old_delta > 0){
                    // r[i-1] is considered
                    ans += compute(up, down);
                    up = 0, down = 0;
                }else if(old_delta == 0){
                    // r[i-1] is considered
                    ans++;
                }else{
                    // r[i-1] is considered because down must contain r[i-1]
                    ans += compute(up, down);
                    up = 0, down = 0;
                }
            }else if(new_delta > 0){
                if(old_delta > 0){
                    // r[i-1] is considered
                    up++;
                }else if(old_delta == 0){
                    // r[i-1] is considered
                    up++;
                }else{
                    // -1 is for r[i-1] because we have to add it to `up` later
                    // otherwise it will be computed twice
                    ans += compute(up, down)-1;
                    up = 0, down = 0;
                    up++;
                }
            }else{
                // r[i-1] > r[i]
                // add r[i] (NOTE: not r[i-1], is r[i] as down!!)
                if(old_delta > 0){
                    // a peak
                    down++;
                }else if(old_delta == 0){
                    down++;
                }else{
                    down++;
                }
            }
            old_delta = new_delta;
            
        }
        ans += compute(up, down);
        return ans;
    }
};
