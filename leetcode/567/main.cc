class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m > n) return false;

        vector<bool> has_char(26, false);
        vector<int> char_count(26, 0);

        int num_char = 0;
        for(int i = 0; i < m; i++){
            int idx = s1[i] - 'a';
            // if this is the first time, add an unique char
            if(char_count[idx]++ == 0){
                num_char++;
                has_char[idx] = true;
            }
        }
        int num_meet = 0;
        for(int i = 0; i < m; i++){
            int idx = s2[i] - 'a';
            // ignore this character if it is not in s1
            if(!has_char[idx]) continue;
            char_count[idx]--;
            if(char_count[idx] == 0) num_meet++; // condition met
            else if(char_count[idx] == -1) num_meet--; // too many
        }
        if(num_meet == num_char) return true;

        for(int i = m; i < n; i++){
            // delete
            int l = s2[i-m] - 'a';
            if(has_char[l]){
                char_count[l]++; // add one back
                if(char_count[l] == 0) num_meet++;
                else if(char_count[l] == 1) num_meet--;
            }
            // add
            int r = s2[i] - 'a';
            if(has_char[r]){
                char_count[r]--; // delete one
                if(char_count[r] == 0) num_meet++;
                else if(char_count[r] == -1) num_meet--;
            }
            if(num_meet == num_char) return true;
        }
        return false;
    }
};
