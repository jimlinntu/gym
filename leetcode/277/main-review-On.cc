/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // a -> b: a is not a candidate
        // a xx b: b is not a candidate
        unordered_set<int> s;
        for(int i = 0; i < n; i++) s.insert(i);
        
        while(s.size() > 1){
            auto it = s.begin();
            auto it2 = s.begin();
            advance(it2, 1);
            int a = *it, b = *it2;
            if(knows(a, b)){
                s.erase(it);
            }else{
                s.erase(it2);
            }
        }
        // Make sure
        int ans = *s.begin();
        for(int i = 0; i < n; i++){
            if(i == ans) continue;
            if(knows(ans, i)) return -1;
            if(knows(i, ans) == false) return -1;
        }
        return ans;
    }
};
