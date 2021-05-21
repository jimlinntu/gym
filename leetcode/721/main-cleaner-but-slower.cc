class Solution {
public:
    // Find the leader (the one whose parent is itself)
    // NOTE: parent[email] might not give the leader!
    //       that's why we need this function
    string find_leader(unordered_map<string, string> &parent,
                      string &s){
        auto it = parent.find(s);
        assert(it != parent.end());
        if(it->second == s){
            return s;
        }
        // path compression
        string p = find_leader(parent, parent[s]);
        parent[s] = p; // point to the top most parent
        return p;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> email2accountidx;
        // parent[email] == the parent of this union
        unordered_map<string, string> parent;
        // Initially, all emails belong to themself (disjoint sets)
        for(int i = 0; i < n; i++){
            vector<string> &emails = accounts[i];
            int m = emails.size();
            for(int j = 1; j < m; j++){
                string &email = emails[j];
                email2accountidx[email] = i; // point to idx of accounts
                parent[email] = email; // itself
            }
        }
        // Unify emails that are in the same accounts[i]
        for(int i = 0; i < n; i++){
            vector<string> &emails = accounts[i];
            int m = emails.size();
            // the leader of the first email
            string leader = find_leader(parent, emails[1]);
            for(int j = 2; j < m; j++){
                // Let all emails belongs to the parent of the first email
                string p = find_leader(parent, emails[j]);
                // this emails[j]'s leader should points to `leader`
                parent[p] = leader;
            }
        }
        // Collate the result
        // email2ansidx[leader email] == the index points to ans
        unordered_map<string, int> email2ansidx;
        vector<vector<string>> ans;
        for(auto it = parent.begin(); it != parent.end(); it++){
            string email = it->first;
            string leader = find_leader(parent, email);
            if(email2ansidx.find(leader) == email2ansidx.end()){
                // record that every email whose leader is `leader`
                // should be place at ans[email2ansidx[leader]]
                email2ansidx[leader] = ans.size();
                ans.push_back({accounts[email2accountidx[email]][0], email});
            }else{
                int idx = email2ansidx[leader];
                ans[idx].push_back(email);
            }
        }
        // Sort emails in each new account
        for(auto &emails: ans) sort(emails.begin()+1, emails.end());
        return ans;
    }
};
