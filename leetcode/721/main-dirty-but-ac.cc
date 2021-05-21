
class Solution {
public:
    int find_root(vector<int> &group, int i){
        if(group[i] == i){
            return i;
        }
        // path compression
        group[i] = find_root(group, group[i]);
        return group[i];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // map[email] == a group idx where this email belongs
        unordered_map<string, int> map;
        // group[i] == j
        //          == this account at i belongs to j
        vector<int> group(n);

        for(int i = 0; i < n; i++){
            vector<string> &emails = accounts[i];
            int m = emails.size();
            // Initially, this group belongs to itself
            group[i] = i;
            // find if this is an isolated group
            int gidx = -1;
            for(int j = 1; j < m; j++){
                auto it = map.find(emails[j]);
                if(it != map.end()){
                    gidx = it->second;
                    break;
                }
            }
            if(gidx == -1){
                // If yes, point these emails to index i
                for(int j = 1; j < m; j++) map[emails[j]] = i;
            }else{
                // Make every email belongs to gidx
                // and each email's group should belong to gidx
                gidx = find_root(group, gidx);
                group[i] = gidx; // i --> gidx
                for(int j = 1; j < m; j++){
                    auto it = map.find(emails[j]);
                    if(it == map.end()){
                        // a new email, just point it to gidx
                        map[emails[j]] = gidx;
                    }else{
                        // points its root to gidx
                        int root = find_root(group, it->second);
                        group[root] = gidx;
                    }
                }
            }
        }

        // Collect the result
        unordered_map<int, int> group2ansidx;
        vector<vector<string>> ans;
        for(auto it = map.begin(); it != map.end(); it++){
            auto &email = it->first;
            int gidx = it->second;
            // Find the group it belongs
            gidx = find_root(group, gidx);
            auto git = group2ansidx.find(gidx);
            if(git == group2ansidx.end()){
                group2ansidx[gidx] = ans.size();
                ans.push_back({accounts[gidx][0], email});
            }else{
                int idx = git->second;
                ans[idx].push_back(email);
            }
        }
        // Sort the emails
        for(auto &emails: ans) sort(emails.begin()+1, emails.end());
        return ans;
    }
};
