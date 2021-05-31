class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        // O(26 * n) = O(n)
        for(int i = 0; i < 26; i++){
            // Search for 'A'+i
            char c = 'A' + i;
            // Two pointers algorithm
            // with k tolerence characters
            int start = 0, end = 0;
            int kk = k;
            while(start < n and end < n){
                if(s[end] == c) end++;
                else if(kk > 0){
                    end++;
                    kk--;
                }else if(end - start == 0){
                    start++;
                    end = start;
                }else{
                    if(s[start] != c) kk++;
                    start++;
                }
                // [start, end)
                ans = max(ans, end - start);
            }
            
        }
        return ans;
    }
};
