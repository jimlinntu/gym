class Solution {
public:
    bool put_color(int cur, int c, vector<vector<int>> &g,
                  vector<int> &color){
        // this node has been colored
        if(color[cur] != -1){
            // check if there is a conflict
            // a conflict occurs
            if(color[cur] != c) return false;
            return true; // same color, return true because this node has been checked
        }
        color[cur] = c;
        for(int nei: g[cur]){
            // put another color
            if(!put_color(nei, (c+1)%2, g, color)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // there is no edge: return true
        if(n < 2) return true;
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] != -1) continue; // already colored
            if(!put_color(i, 0, graph, color)) return false;
        }
        return true;
    }
};
