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
        default_random_engine e(4);
        shuffle(wordlist.begin(), wordlist.end(), e);

        for(int i = 0; i < 10; i++){
            string &w = wordlist[0];
            int c = master.guess(w);
            if(c == 6) break;
            // if count_same(wordlist[i], w) != c
            // we know that this will not be the answer
            vector<string> new_wordlist;
            for(int j = 0; j < wordlist.size(); j++){
                if(count_same(wordlist[j], w) == c)
                    new_wordlist.push_back(wordlist[j]);
            }
            wordlist = new_wordlist;
        }
        return;
    }
};
