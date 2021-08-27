class Solution {
public:
    // 0: north, 1: east, 2: south, 3: west
    int dir[4][2] = {{0, +1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isRobotBounded(string s) {
        int face = 0;
        unordered_map<char, int> map = {{'L', +3}, {'R', +1}};
        int move[2] = {0, 0};
        // Simulate once
        int n = s.size();
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == 'G'){
                move[0] += dir[face][0];
                move[1] += dir[face][1];
            }else{
                face = (face + map[c]) % 4; // change the direction;
            }
        }
        if(move[0] == 0 and move[1] == 0) return true;
        if(face == 0) return false; // if the ending direction is north --> will not end
        return true;
    }
};
