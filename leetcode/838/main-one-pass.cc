class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        if(n == 0) return "";
        int prev_right = -1;
        // Idea: we push dominoes only when we meet the "next" one!
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R'){
                if(prev_right != -1){
                    // Case: R . . . R
                    //    => R R R R R
                    for(int j = prev_right+1; j < i; j++) dominoes[j] = 'R';
                }    
                prev_right = i;
            }
            else if(dominoes[i] == 'L'){
                if(prev_right == -1){
                    // there is no 'R' on the left
                    // Case 1: . . . . . . L
                    //      => L L L L L L L
                    // Case 2: R . . L . . L
                    //      => R R L L L L L
                    for(int j = i-1; j >= 0; j--){
                        // stop if a domino is not vertical
                        if(dominoes[j] != '.') break;
                        dominoes[j] = 'L';
                    }
                }else{
                    // there is a 'R' on the left
                    // Case 1:  R . . . L
                    //              ^ <----mid
                    // Case 2:  R . . L
                    //              ^ <----mid
                    int mid = (prev_right + i + 1) / 2;
                    for(int j = prev_right+1; j < mid; j++){
                        dominoes[j] = 'R';
                    }
                    // Case 1:  R . . . L
                    //              ^ <----mid
                    // Case 2:  R . . L
                    //            ^ <----mid
                    mid = (prev_right + i) / 2;
                    for(int j = mid+1; j < i; j++){
                        dominoes[j] = 'L';
                    }
                    // reset it because this propagation cannot pass over j
                    prev_right = -1;
                }
            }
        }
        // Case: R . . . . . (no L on the right)
        //    => R R R R R R
        if(prev_right != -1){
            for(int i = prev_right+1; i < n; i++){
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
