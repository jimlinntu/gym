class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n) return false;
        vector<int> holes(26, 0);
        // the goal is to find whether there is a substring in s2 that can fill up these holes
        for(int i = 0; i < m; i++){
            holes[s1[i] - 'a']--;
        }
        int l = 0, r = 0;
        while(r < n){
            // fill a character into the hole
            int r_idx = s2[r++] - 'a';
            holes[r_idx]++;
            // dig the characters out until holes[r_idx] == 0 if holes[r_idx] == 1 at first
            while(l < r and holes[r_idx] > 0){
                holes[s2[l++]-'a']--;
            };
            // if we have put (r-l) characters inside the hole,
            // and we can still maintain holes[r_idx] == 0,
            // that means all holes are zeros!
            /*
                Proof by contradiction:
                if (r - l) == m and there exists a idx s.t. holes[idx] != 0

                1) holes[idx] > 0, it must be fixed into 0 by the while loop on top, so it cannot happen.
                2) holes[idx] < 0, however, we have put m characters inside the hole. And sum(holes) + m == 0.
                   so there must exist an j s.t. holes[j] > 0.
                   However, by our algorithm, if we reach j and holes[j] > 0, we will fix it into 0.
                   Therefore, this will not happen too.
                
                In conclusion, we are sure for all i, holes[i] == 0
            */
            if(r - l == m) return true;
        }
        return false;
    }
};
