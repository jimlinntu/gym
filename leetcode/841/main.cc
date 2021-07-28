class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        // rooms[i] == indices of the room we can enter
        //          == neighbors!
        int count = 0;
        stack<int> stk;
        vector<bool> key_we_have(n, false);
        stk.push(0);
        key_we_have[0] = true;
        count++;
        while(!stk.empty()){
            int cur = stk.top();
            stk.pop();
            for(int key: rooms[cur]){
                if(key_we_have[key]) continue;
                key_we_have[key] = true;
                stk.push(key); // collect all keys
                count++;
            }
        }
        return count == n;
    }
};
