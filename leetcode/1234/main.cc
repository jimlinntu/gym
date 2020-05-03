int char2idx(char c){
    switch(c){
        case 'Q':
            return 0;
            break;
        case 'W':
            return 1;
            break;
        case 'E':
            return 2;
            break;
        case 'R':
            return 3;
            break;
        default:
            assert(false);
    }
}

bool meet_criterions(int criterions[4], int contain[4]){
    for(int i = 0; i < 4; i++){
        if(contain[i] < criterions[i]) return false;
    }
    // if contain[i] >= criterions[i] for all i, then this subarray must be
    // "convertible"!
    // You can think it as "sharing" the redundant characters to other characters
    return true;
}
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int answer = n; // array of length n must be "convertible" (a valid answer)
        int counter[4] = {0}, criterions[4] = {0}, contain[4] = {0};
        int i = 0, j = 0;
        // First pass: compute counter[Q or W or E or R]
        for(int i = 0; i < n; i++){
            counter[char2idx(s[i])]++;
        }
        // Compute criterions
        bool is_valid = true;
        for(int i = 0; i < 4; i++){
            // criterions[i] represent the number of redundant i character
            criterions[i] = max(0, counter[i] - n/4);
            if(criterions[i] != 0) is_valid = false;
        }
        if(is_valid) return 0; // already a balanced string
        //
        while(j < n){
            // update the contain data structure
            contain[char2idx(s[j++])]++;
            //
            for(; i < j && meet_criterions(criterions, contain); i++){
                answer = min(answer, j - i);
                // remove s[i] char
                contain[char2idx(s[i])]--;
            }
        }
        return answer;
    }
};
