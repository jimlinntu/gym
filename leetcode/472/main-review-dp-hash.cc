class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> S;
        bool dp[1001];
        // Sort by lengths
        sort(words.begin(), words.end(),
             [](const string &l, const string &r) -> bool{
            return l.size() < r.size();
        });
        // Build the hash table on the fly
        // NOTE: This solution assume words are unqiue!
        //       if the words are not unique, it will fail because
        //       dp[w.size()] will be flawed!
        int n = words.size();
        for(int i = 0; i < n; i++){
            string &w = words[i];
            if(w == "") continue;
            fill(dp, dp+w.size()+1, false);
            dp[0] = true;
            // NOTE:
            // because S.count(w) == 0(has not yet added)
            // it implicitly define
            // dp[w.size()] differently!
            // dp[j < w.size()] all allow a word form by itself!
            for(int len = 1; len <= w.size(); len++){
                for(int k = 0; k < len; k++){
                    dp[len] = dp[k] and S.count(w.substr(k, len-k));
                    if(dp[len]) break;
                }
            }
            if(dp[w.size()]) ans.push_back(w);

            S.insert(w);
        }
        return ans;
    }
};
