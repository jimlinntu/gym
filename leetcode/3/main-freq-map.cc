int char2int(char c){
    int num = (int)c-(int)'\0';
    return num;
}
class Solution {
public:
    int freq[256];
    int lengthOfLongestSubstring(string s) {
        fill(freq, freq+256, 0);
        int n = s.length();
        int r = 0;
        int max_len = 0;
        for(int i = 0; i < n; i++){
            // window: [i, r) is a substring w/o repeating chars
            while(r < n and freq[char2int(s[r])] == 0){
                freq[char2int(s[r])]++;
                r++;
            }
            if(r - i > max_len){
                max_len = r - i;
            }
            // remove a char from i
            freq[char2int(s[i])] = 0;
        }
        return max_len;
    }
};
