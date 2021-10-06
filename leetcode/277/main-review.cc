/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // a -> b: a is not a candidate
        // a xx b: b is not a candidate
        int cand = 0;
        for(int i = 1; i < n; i++){
            if(knows(cand, i)){
                // candidate cannot be a possible sol anymore
                cand = i;
            }
        }
        // Verify
        for(int i = 0; i < n; i++){
            if(i == cand) continue;
            if(knows(cand, i)) return -1;
            if(knows(i, cand) == false) return -1;
        }
        return cand;
    }
};
