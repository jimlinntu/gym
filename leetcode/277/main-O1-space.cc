/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int c = 0;
        for(int i = 1; i < n; i++){
            if(knows(i, c)){
                // If i knows c, then i is not a celebrity
            }else{
                // If i does not know c, c is not a celebrity
                c = i;
            }
        }
        // Check if this celebrity is real
        for(int i = 0; i < n; i++){
            if(i == c) continue;
            if(!knows(i, c)) return -1;
            if(knows(c, i)) return -1;
        }
        return c;
    }
};
