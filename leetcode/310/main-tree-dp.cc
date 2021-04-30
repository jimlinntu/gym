using Graph = vector<vector<int>>;
class Solution {
public:
    // compute highest[i] and secondhighest[i]
    void compute(int i, int parent,
                 vector<int> &highest, vector<int> &secondhighest,
                 Graph &g){
        for(int child: g[i]){
            if(child == parent) continue;
            compute(child, i, highest, secondhighest, g);
            int height = highest[child]+1;

            if(height > highest[i]){
                secondhighest[i] = highest[i];
                highest[i] = height;
            }else if(height > secondhighest[i]){
                secondhighest[i] = height;
            }
        }
        // leaf node's highest[i] and secondhighest[i] are 0s
        return;
    }
    // Compute dp[i] (the height of a tree rooted at i)
    void tree_dp(int i, int parent, int the_longest_path_from_i,
                 vector<int> &highest, vector<int> &secondhighest,
                 vector<int> &dp, Graph &g){
        dp[i] = max(the_longest_path_from_i, highest[i]);
        for(int child: g[i]){
            if(child == parent) continue;
            int the_longest_path_from_child = \
                1 + ((highest[child] + 1 == highest[i])? (secondhighest[i]):(highest[i]));
            the_longest_path_from_child = max(the_longest_path_from_child, the_longest_path_from_i+1);
            tree_dp(child, i, the_longest_path_from_child, highest, secondhighest, dp, g);
        }
        return;
    }

    void build_graph(vector<vector<int>> &edges, Graph &g){
        for(auto &edge: edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> highest(n, 0);
        vector<int> secondhighest(n, 0);
        vector<int> dp(n, 0);
        vector<int> ans;
        Graph g(n);
        build_graph(edges, g);
        compute(0, -1, highest, secondhighest, g);
        tree_dp(0, -1, 0, highest, secondhighest, dp, g);

        int min_h = *min_element(dp.begin(), dp.end());
        for(int i = 0; i < n; i++){
            if(dp[i] == min_h) ans.push_back(i);
        }
        return ans;
    }
};
