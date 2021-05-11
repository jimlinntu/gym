class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        if(k == 0) return ans;
        vector<int> path(k, 0);
        int idx = 0;
        // It is an iterative version of a DFS
        // Ex. n == 4, k == 33
        // You can imagine we have a root
        // root -> 1 --> 2 --> 3
        //                 --> 4
        //           --> 3 --> 4
        // root -> 2 --> 3 --> 4
        // When idx == -1, it means we have already traversed all children of the root
        // idx is reprensting the depth we are in now
        while(idx >= 0){
            path[idx]++;
            if(path[idx] > n){
                // step back because we have tried all children
                idx--;
                continue;
            }
            idx++; // step one
            // We already reach the end
            if(idx == k){
                ans.push_back(path);
                // one step back!
                idx--;
                continue;
            }
            // Every children should be **greater than** its father!
            // so we set it as path[i-1] so that it will be incremented at the start of the loop
            path[idx] = path[idx-1];
        }
        return ans;
    }
};
