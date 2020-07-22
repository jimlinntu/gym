using Net = vector<vector<int>>;
class Solution {
public:
    int n;
    int word_len; 
    int begin_idx;
    int end_idx;
    Net wordNet;
    bool is_edge(string &w1, string &w2){
        int counter = 0;
        for(int i = 0; i < word_len && counter < 2; i++){
            counter += (w1[i] != w2[i]);
        }
        return counter == 1;
    }
    int build_wordnet(string &beginWord, string &endWord,
                      vector<string> &wordList){
        // Build the connections between words
        for(int i = 0; i < n; i++){
            auto &w_i = wordList[i];
            for(int j = i+1; j < n; j++){
                auto &w_j = wordList[j];
                if(is_edge(w_i, w_j)){
                    wordNet[i].push_back(j);
                    wordNet[j].push_back(i);
                }
            }
        }
        // Build the edges between the beginWord and other words
        int end_idx = -1;
        for(int i = 0; i < n; i++){
            if(is_edge(beginWord, wordList[i])){
                wordNet[begin_idx].push_back(i);
                wordNet[i].push_back(begin_idx);
            }
            if(wordList[i] == endWord){
                end_idx = i;
            }
        }
        return end_idx;
    }
    int bibfs_find_shortest_path(){
        // 0 is for forward search, 1 is for backward search
        vector<vector<int>> dist(2, vector<int>(n+1, -1));
        queue<int> q[2];
        // Initialization
        q[0].push(begin_idx);
        q[1].push(end_idx);
        dist[0][begin_idx] = 0;
        dist[1][end_idx] = 0;
        
        int meet_idx = -1;
        int round = 0;
        while(!q[0].empty() && !q[1].empty() && meet_idx == -1){
            int cur = q[round].front();
            q[round].pop();
            for(int i: wordNet[cur]){
                if(dist[round][i] == -1){
                    dist[round][i] = dist[round][cur] + 1;
                    q[round].push(i);
                    // if another side has found this node
                    if(dist[round ^ 1][i] != -1){
                        meet_idx = i;
                        break;
                    }
                }
            }
            round ^= 1;
        }
        if(meet_idx != -1) return dist[0][meet_idx] + dist[1][meet_idx] + 1;
        else return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        if(n == 0) return 0;
        word_len = wordList[0].length();
        begin_idx = n;
        wordNet = Net(n+1); // including the beginWord
        end_idx = build_wordnet(beginWord, endWord, wordList);
        if(end_idx == -1) return 0;
        return bibfs_find_shortest_path();
    }
};
