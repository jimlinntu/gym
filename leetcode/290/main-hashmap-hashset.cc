class Solution {
public:
    bool get_word(string &s, int &start, string &word){
        if(start >= s.size()) return false;
        int end = start;
        // until encounter a ' ' or EOF
        for(; end < s.size() and s[end] != ' '; end++){
        }
        word = s.substr(start, end-start);
        start = end;
        return true;
    }
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        unordered_set<string> set;
        unordered_map<char, string> map;
        int i = 0, j = 0;
        for(; i < n; i++){
            char c = pattern[i];
            string word;
            if(!get_word(s, j, word)) return false;
            j++;
            // if this character does not exist, we add this word
            // NOTE: this word should be unique!
            // Ex. abba cannot be dog dog dog dog
            if(map.find(c) == map.end() and set.find(word) == set.end()){
                map[c] = word;
                set.insert(word);
            }else if(map[c] == word){
                // good, do nothing
            }else return false;
        }
        // if we still have characters inside our string,
        // # of words > # of characters in the pattern
        if(j < s.size()) return false;
        return true;
    }
};
