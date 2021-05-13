class Solution {
public:
    int get_bit_len(int num){
        // O((log n) * (log n))
        int bit_len = 0;
        while(num > 0){
            bit_len++;
            num >>= 1;
        }
        return bit_len;
    }
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        int bit_len = get_bit_len(num);
        vector<int> c(num+1);
        // BFS:
        // 000 --> 001
        //     --> 010 --> 011
        //     --> 100 --> 101
        //             --> 110 --> 111
        int depth = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            for(int i = q.size()-1; i >= 0; i--){
                int cur = q.front();
                q.pop();
                c[cur] = depth;
                // Add its neighbors
                int neighbor;
                for(int offset = 0, mask = 1; offset < bit_len;
                        offset++, mask <<= 1){
                    if((cur & mask) != 0) break;
                    neighbor = cur | mask;
                    if(neighbor > num) break;
                    q.push(neighbor);
                }
            }
            depth++;
        }
        return c;
    }
};
