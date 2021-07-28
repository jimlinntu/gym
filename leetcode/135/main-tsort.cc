class Solution {
public:
    int candy(vector<int>& r) {
        // Establish an acyclic graph and then starting from leaf node
        // and set them as `layer_num_canday` and then increment layer_num_candy
        // and then remove the curent leaves and then continue the loop
        // It is like a graph DP
        // because if an i does not have any r[i] > r[i-1] or r[i] > r[i+1]
        // we must set it as 1 because we want to minimize the number of candy
        int n = r.size();
        vector<int> outdeg(n, 0);
        for(int i = 1; i < n; i++){
            if(r[i-1] < r[i]){
                outdeg[i]++;
            }else if(r[i-1] > r[i]){
                outdeg[i-1]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(outdeg[i] == 0) q.push(i);
        }

        int ans = 0;
        int layer_num_candy = 1;
        while(!q.empty()){
            for(int i = q.size()-1; i >= 0; i--){
                int cur = q.front();
                q.pop();
                // Find its parent
                if(cur-1 >= 0 and r[cur-1] > r[cur]){
                    if(--outdeg[cur-1] == 0)
                        q.push(cur-1);
                }
                if(cur+1 < n and r[cur+1] > r[cur]){
                    if(--outdeg[cur+1] == 0)
                        q.push(cur+1);
                }
                
                ans += layer_num_candy;
            }
            layer_num_candy++;
        }
        return ans;
    }
};
