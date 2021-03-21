class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        int count[26] = {0};
        int max_freq = 0;
        for(int i = 0; i < n; i++){
            int c = ++count[S[i]-'a'];
            if(c > max_freq){
                max_freq = c;
            }
        }
        int num_partition = max_freq-1;
        // record those characters with the max frequency
        string max_chars;
        for(int i = 0; i < 26; i++){
            if(count[i] == max_freq) max_chars.push_back(i+'a');
        }
        // there is no enough characters to fill one character at least for each parition
        // NOTE: a b | a b | a b can be a valid result!
        //       so we only need to check (n - max_freq) < num_partition
        //       rather than (m - max_freq * max_chars.size()) < num_partition
        if(n - max_freq < num_partition) return "";
        // a 0 3 a 1 4 a 2 5 a
        vector<char> chars(n-max_freq*max_chars.size());
        int length = 0;
        // fill characters into chars
        for(int i = 0; i < 26; i++){
            if(count[i] == max_freq) continue;
            // fill count[i] chars into chars
            for(int j = 0; j < count[i]; j++){
                chars[length++] = i + 'a';
            }
        }
        assert(length == chars.size());
        // Unfold chars from:
        //        a 0 3 a 1 4 a 2 5 a
        // mod ==   0 0   1 1   2 2
        // to the answer string
        string ans;
        ans += max_chars; // Ex. a b ? ? | a b ? ? | a b ? ?
        // O(n) algorithm (though there are two loops)
        for(int i = 0; i < num_partition; i++){
            // append those indices of mod == i
            for(int j = i; j < length; j += num_partition){
                ans.push_back(chars[j]);
            }
            ans += max_chars;
        }
        return ans;
    }
};
