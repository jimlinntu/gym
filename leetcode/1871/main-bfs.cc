class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int r = 0; // the rightmost we can reach
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int u = min(n, cur+maxJump+1);
            for(int i = max(cur+minJump, r+1); i < u; i++){
                if(s[i] != '0') continue;
                if(i == n-1) return true;
                q.push(i);
            }
            // prevent duplicate traversals
            r = max(r, cur+maxJump);
        }
        return false;
    }
};
