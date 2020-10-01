using Map = unordered_map<string, int>;
using Words = vector<string>;
class Solution {
private:
    // the max(word lengths) == 300 --> len(w + "#" + rev_w) == 601
    int lsp[601]; // the longest proper prefix which is also a suffix
public:
    void compute_lsp(string &s){
        int n = s.length();
        int len = 0;
        lsp[0] = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == s[len]){
                lsp[i] = ++len;
            }else{
                // Stop when s[i] and s[len] are equal
                while(len != 0 and s[i] != s[len]){
                    len = lsp[len-1]; // get the proper prefix of s[0:len-1] (boundaries included)
                }
                if(s[i] == s[len]) len++;
                lsp[i] = len;
            }
        }
        return;
    }
    void compute(Words &words, Map &str2idx, vector<vector<int>> &ans){
        int n = words.size();
        int palin_len;
        // O(nm^2) in total
        for(int i = 0; i < n; i++){
            string &w = words[i];
            string rev_w(w);
            reverse(rev_w.begin(), rev_w.end());
            string t1 = w + "#" + rev_w;
            string t2 = rev_w + "#" + w;
            compute_lsp(t1); // O(m)
            palin_len = t1.length();
            // O(m^2) while loop
            while(palin_len != 0){
                palin_len = lsp[palin_len-1];
                // compute a left so that p = left + w and p is a palin;
                string left(w.begin()+palin_len, w.end());
                reverse(left.begin(), left.end());
                // check if this string exist in the words
                auto it = str2idx.find(left);
                if(it != str2idx.end()){
                    // avoid duplicate pairs:
                    // because if len(left) == len(w) and i >= str2idx(left)
                    // (= is because "distinct" indices)
                    // that means we already have this pair!
                    if(left.length() == w.length() and i >= it->second) continue;
                    ans.push_back({it->second, i});
                }
            }
            compute_lsp(t2);
            palin_len = t2.length();
            while(palin_len != 0){
                palin_len = lsp[palin_len-1];
                // palin = w + right
                string right(w.begin(), w.begin()+(w.length()-palin_len));
                reverse(right.begin(), right.end());
                auto it = str2idx.find(right);
                if(it != str2idx.end()){
                    if(right.length() == w.length() and i >= it->second) continue;
                    ans.push_back({i, it->second});
                }
            }
        }
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        Map str2idx;
        int n = words.size();
        for(int i = 0; i < n; i++){
            str2idx[words[i]] = i;
        }
        compute(words, str2idx, ans);
        return ans;
    }
};
