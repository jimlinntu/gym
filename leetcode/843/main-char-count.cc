/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int count_same(string &l, string &r){
        int c = 0;
        for(int i = 0; i < 6; i++)
            c += (l[i] == r[i]);
        return c;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        // https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison
        // Because (25/26)^6 ~= 80%
        // most of the time we will get count_same(cur, secret) = 0
        // If that is the case,
        // we can eliminate every word that satisfy count_same(cur, word) >= 1
        //
        // So which word should we choose?
        // Choose a word that
        // has the biggest sum(1 for w in words if count_same(word, w) >= 1)
        // Because if count_same(word, secret) = 0
        // we can eliminate lots of words!
        int char_count[6][26] = {{0}};
        for(int i = 0; i < wordlist.size(); i++){
            for(int j = 0; j < 6; j++){
                char_count[j][wordlist[i][j]-'a']++;
            }
        }
        for(int i = 0; i < 10; i++){
            // choose a word that has the most number of overlapped
            int score = INT_MIN;
            int idx = -1;
            for(int j = 0; j < wordlist.size(); j++){
                int s = 0;
                for(int k = 0; k < 6; k++){
                    // NOTE: s may not be able to properly reflect the 
                    //       the true overlap
                    // For example, if w1 = abcdef, w2 = abcdef
                    // `ab` will add 2 into `s`
                    // But that's ok, because it is already a good es
                    s += char_count[k][wordlist[j][k]-'a'];
                }
                if(s > score){
                    score = s;
                    idx = j;
                }
            }
            string &w = wordlist[idx];
            int cnt = master.guess(w);
            if(cnt == 6) break;
            // Only leave count_same(w, word) == cnt;
            vector<string> new_words;
            for(int j = 0; j < wordlist.size(); j++){
                if(count_same(wordlist[j], w) == cnt){
                    new_words.push_back(wordlist[j]);
                }else{
                    // change char_count (because of removal)
                    for(int k = 0; k < 6; k++){
                        char_count[k][wordlist[j][k]-'a']--;
                    }
                }
            }
            wordlist = new_words;
        }
        return;
    }
};
