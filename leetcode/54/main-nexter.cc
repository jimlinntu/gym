struct Nexter{
    int i, j;
    int m, n;
    int dir;
    // Starting from null position (-1, -1)
    Nexter(int mm, int nn): i(-1), j(-1), m(mm), n(nn), dir(0) {};
    pair<int, int> get_next(){
        if(i == -1 and j == -1){
            i = 0, j = 0;
            return {0, 0};
        }
        // Move until we reach (0, n-1)
        if(i == 0 and j < n-1){
            return {0, ++j};
        }
        // If before we move, we have already each the end
        // , we are sure this spiral ends
        if(reach_end()){
            i = -1, j = -1;
            dir = 0;
            return {-1, -1};
        }
        switch(dir % 4){
            case 0:
                i++;
                break;
            case 1:
                j--;
                break;
            case 2:
                i--;
                break;
            case 3:
                j++;
                break;
            default:
                assert(false);
        }
        // turn the direction if we reach the end
        if(reach_end()) dir++;
        return {i, j};
    }
    bool reach_end(){
        // A round is composed of (down, left, up, right)
        int round = dir / 4;
        switch(dir % 4){
            case 0:
                if(i == m-1-round) return true;
                break;
            case 1:
                if(j == round) return true;
                break;
            case 2:
                if(i == round+1) return true;
                break;
            case 3:
                if(j == n-2-round) return true;
                break;
            default:
                assert(false);
        }
        return false;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        Nexter nexter(m, n);
        while(true){
            int i, j;
            tie(i, j) = nexter.get_next();
            if(i == -1 and j == -1) break;
            ans.push_back(matrix[i][j]);
        }
        return ans;
    }
};
