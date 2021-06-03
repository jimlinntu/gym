class Solution {
public:
    bool appear[26] = {false};
    string ans;
    void bfs_tsort(unordered_set<int> graph[]){
        int indeg[26] = {0};
        for(int i = 0; i < 26; i++){
            if(!appear[i]) continue;
            for(int neighbor: graph[i]){
                indeg[neighbor]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < 26; i++){
            // If there is no one pointing to it
            // that means this character is the smallest
            if(appear[i] and indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            indeg[cur]--;
            ans.push_back(cur+'a');

            for(int neighbor: graph[cur]){
                // if indeg[neighbor] == 0 indicates we are ready to visit it
                if(--indeg[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
    }
    string alienOrder(vector<string>& words) {
        int n = words.size();
        // next_char[i] = {j+'a' where char i+'a' < char j+'a'}
        unordered_set<int> graph[26];
        for(char c: words[0]) appear[c-'a'] = true;
        for(int i = 0; i < n-1; i++){
            for(char c: words[i+1]) appear[c-'a'] = true;
    
            int min_len = min(words[i].size(), words[i+1].size());
            // Build a relational map
            for(int j = 0; j < min_len; j++){
                if(words[i][j] == words[i+1][j]) continue;
                // Build a relation of the first non-equal characters
                graph[words[i][j]-'a'].insert(words[i+1][j]-'a');
                break;
            }
            // Ex. aaa aa aaa
            // This should be an invalid order
            if(words[i].substr(0, min_len) == words[i+1].substr(0, min_len) and
               words[i].size() > words[i+1].size()) return "";
        }
        // Output relation (and detect cycle)
        bfs_tsort(graph);
        int count = 0;
        for(int i = 0; i < 26; i++) count += appear[i];
        // If there is a cycle, there will some nodes that cannot be traversed
        // because of indeg[*] > 0
        if(ans.size() != count) return "";
        return ans;
    }
};
