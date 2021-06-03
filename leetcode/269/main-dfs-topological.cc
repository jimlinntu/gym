class Solution {
public:
    string ans;
    bool path[26] = {false};
    bool visited[26] = {false};
    bool tsort(unordered_set<int> graph[], int cur){
        if(path[cur]) return true;
        // Subtree under this cur has already been visited
        if(visited[cur]) return false;
        path[cur] = visited[cur] = true;
        bool has_cycle = false;
        for(int neighbor: graph[cur]){
            has_cycle |= tsort(graph, neighbor);
            if(has_cycle) break;
        }
        // Leave this node, mark path as false
        path[cur] = false;
        ans.push_back(cur+'a');
        return has_cycle;
    }
    string alienOrder(vector<string>& words) {
        // ab, ca, cd, cc
        // a <-- c
        // a <-- d <-- c
        // Ex.
        // a < d < c
        // g < d < e
        // a ag ad ae d c
        // Ex. a b c d a
        // a < b < c < d < a

        int n = words.size();
        // next_char[i] = {j+'a' where char i+'a' > char j+'a'}
        bool appear[26] = {false};
        unordered_set<int> graph[26];
        for(char c: words[0]) appear[c-'a'] = true;
        for(int i = 0; i < n-1; i++){
            for(char c: words[i+1]) appear[c-'a'] = true;
            int min_len = min(words[i].size(), words[i+1].size());
            // Build a relational map
            for(int j = 0; j < min_len; j++){
                if(words[i][j] == words[i+1][j]) continue;
                // Build a relation of the first non-equal characters
                graph[words[i+1][j]-'a'].insert(words[i][j]-'a');
                break;
            }
            // Ex. aaa aa aaa
            // This should be an invalid order
            if(words[i].substr(0, min_len) == words[i+1].substr(0, min_len) and
               words[i].size() > words[i+1].size()) return "";
        }
        // Output relation (and detect cycle)
        for(int i = 0; i < 26; i++){
            if(!appear[i]) continue;
            if(tsort(graph, i)) return "";
        }
        return ans;
    }
};
