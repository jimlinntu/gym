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
                // add an undirectional edge from the beginWord to i
                wordNet[begin_idx].push_back(i);
            }
            if(wordList[i] == endWord){
                end_idx = i;
            }
        }
        return end_idx;
    }
    int find_shortest_path(){
        vector<int> dist(n+1, -1);
        queue<int> q;
        bool found = false;
        q.push(begin_idx);
        dist[begin_idx] = 0;
        while(!q.empty() && !found){
            int cur = q.front();
            q.pop();
            for(auto i: wordNet[cur]){
                if(dist[i] != -1) continue;
                q.push(i);
                dist[i] = dist[cur] + 1;
                if(i == end_idx){
                    found = true;
                    break;
                }
            }
        }
        return dist[end_idx]+1; // convert # of steps to # of words
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        if(n == 0) return 0;
        word_len = wordList[0].length();
        begin_idx = n;
        wordNet = Net(n+1); // including the beginWord
        end_idx = build_wordnet(beginWord, endWord, wordList);
        if(end_idx == -1) return 0;
        return find_shortest_path();
    }
};
