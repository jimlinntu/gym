class Solution {
public:
    vector<string> ans;
    vector<string> fullJustify(vector<string>& words, int maxW) {
        int n = words.size();
        int start = 0;
        int word_len = 0;
        for(int i = 0; i < n; i++){
            string &w = words[i];
            // Try adding this word
            // NOTE: (i - start) is the minimum # of slots when we add this word
            if((word_len + (i - start) + w.size()) <= maxW){
                assert(w.size() <= maxW);
                word_len += w.size();
            }else{
                // Add [start, i) to the ans
                int num_words = (i- start);
                assert(num_words >= 1);
                string s = words[start];
                if(num_words >= 2){
                    int num_spaces = (maxW - word_len) / (num_words-1);
                    int remainder = (maxW - word_len) % (num_words-1);

                    for(int j = start+1; j < i; j++){
                        // add spaces
                        s += string(num_spaces + (remainder > 0), ' ');
                        remainder--; // put spaces on the left first
                        // add a word
                        s += words[j];
                    }
                }else{
                    // left justified because it has only one word
                    s += string(maxW - word_len, ' ');
                }
                ans.push_back(s);
                // Open a newline
                start = i;
                word_len = w.size(); 
            }
        }
        // The last line should be left justified
        assert(word_len > 0);
        string s = words[start];
        for(int i = start+1; i < n; i++){
            s += " " + words[i];
        }
        s += string(maxW - word_len - (n - start - 1), ' ');
        ans.push_back(s);
        return ans;
    }
};
