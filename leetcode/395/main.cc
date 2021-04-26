constexpr int c2i(char c){
    return c - 'a';
}
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();
        int freq[26];
        // A window must contain different numbers of unique characters
        // NOTE:
        for(int num_uniq = 1; num_uniq <= 26; num_uniq++){
            fill_n(freq, 26, 0);
            int start = 0, end = 0;
            // the number of the unique characters with the current window: [start, end)
            int num_uniq_in_the_window = 0;
            int count_at_least_k = 0;
            while(true){
                if(end < n and num_uniq_in_the_window <= num_uniq){
                    // add s[end]
                    if(freq[c2i(s[end])]++ == 0) num_uniq_in_the_window++;
                    if(freq[c2i(s[end])] == k) count_at_least_k++;
                    end++;
                }
                if(num_uniq_in_the_window == num_uniq and count_at_least_k == num_uniq)
                    ans = max(ans, end - start);

                // When we encounter overflows, we have to throw away a character
                if(num_uniq_in_the_window > num_uniq){
                    // delete s[start]
                    if(freq[c2i(s[start])] == k) count_at_least_k--;
                    if(--freq[c2i(s[start])] == 0) num_uniq_in_the_window--;
                    start++;
                }else if(end == n){
                    // Because there is no more character that can be added,
                    // we can just break
                    assert(num_uniq_in_the_window <= num_uniq);
                    break;
                }
            }
        }
        return ans;
    }
};
