/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // Possible candidates
        unordered_set<int> candidates;
        for(int i = 0; i < n; i++) candidates.insert(i);

        while(candidates.size() > 1){
            int c1 = *candidates.begin();
            int c2 = *(++candidates.begin());
            if(knows(c1, c2)){
                // c1 is not a celebrity
                candidates.erase(c1);
            }else{
                candidates.erase(c2);
            }
        }
        // Check if every knows this candidate
        int c = *candidates.begin();
        for(int i = 0; i < n; i++){
            if(i == c) continue;
            // Everyone should know this celebrity
            if(!knows(i, c)) return -1;
            // This celebrity should not know other ones
            if(knows(c, i)) return -1;
        }
        // O(3 * n)
        return c;
    }
};
