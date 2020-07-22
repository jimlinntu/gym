using Net = vector<vector<int>>;

class Solution {
public:
    bool contain_edge(string &w1, string &w2){
        int diff_counter = 0;
        int word_len = w1.size();
        // Early break if diff_counter == 2
        for(int i = 0; i < word_len && diff_counter < 2; i++){
            diff_counter += (w1[i] != w2[i]);
        }
        return diff_counter == 1;
    }
    int buildWordNet(
        Net &wordNet,
        vector<string> &wordList,
        string &beginWord, string &endWord){
        int n = wordList.size();
        int target_idx = -1;
        if(n == 0) return target_idx;

        for(int i = 0; i < n; i++){
            auto &w_i = wordList[i];
            for(int j = i+1; j < n; j++){
                auto &w_j = wordList[j];
                if(contain_edge(w_i, w_j)){
                    // build bidirectional edges between w_i and w_j
                    wordNet[i].push_back(j);
                    wordNet[j].push_back(i);
                }
            }
        }

        // Add beginWord into the wordNet
        for(int i = 0; i < n; i++){
            if(contain_edge(beginWord, wordList[i])){
                // build an unidirectional edge
                // (NB: from i to n, because we will perform backward-search down below)
                wordNet[i].push_back(n);
            }
            if(wordList[i] == endWord){
                assert(target_idx == -1);
                target_idx = i;
            }
        }
        return target_idx;
    }
    void restore_paths(int cur, int target_idx,
                       string &beginWord,
                       vector<string> &wordList,
                       vector<vector<int>> &parents,
                       vector<string> &path,
                       vector<vector<string>> &ans_paths){
        int n = wordList.size();
        // index n is the beginWord
        if(cur != n) path.push_back(wordList[cur]);
        else path.push_back(beginWord);
        // if the target_idx is reached, we push the whole path into the answer
        if(cur == target_idx){
            ans_paths.push_back(path);
        }

        for(auto next: parents[cur]){
            restore_paths(next, target_idx,
                          beginWord, wordList, parents, path, ans_paths);
        }
        path.pop_back(); // leave this node
        return;
    }
    void search_transformation(
        string &beginWord,
        Net &wordNet, vector<string> &wordList,
        int target_idx,
        vector<vector<string>> &ans_paths){
        int n = wordList.size();

        // NB: a node might have multiple parents
        vector<vector<int>> parents(n+1);
        vector<int> dist(n+1, -1); // -1 as infinite

        // The trick is to backward-search from the target_idx and define the goal as n
        bool found = false;
        queue<int> q;
        q.push(target_idx);
        dist[target_idx] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            // if we find the begin word
            if(cur == n){
                found = true;
                break;
            }
            for(auto i: wordNet[cur]){
                // have not visit this point
                if(dist[i] == -1){
                    dist[i] = dist[cur] + 1;
                    parents[i].push_back(cur);
                    q.push(i);
                }else if(dist[i] == dist[cur] + 1){
                    // save the current node as an alternative of this node
                    parents[i].push_back(cur);
                }
            }
        }
        // restore answer paths from parents
        if(found){
            vector<string> path;
            restore_paths(n, target_idx,
                          beginWord, wordList, parents, path, ans_paths);
        }
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        Net wordNet(n+1); // index n is for beginWord
        vector<vector<string>> paths;
        int target_idx = buildWordNet(wordNet, wordList, beginWord, endWord);
        if(target_idx == -1) return paths;
        search_transformation(beginWord, wordNet, wordList, target_idx, paths);
        
        return paths;
    }
};
