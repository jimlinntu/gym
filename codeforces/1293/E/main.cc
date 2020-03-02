#include <bits/stdc++.h>
#define MAXN 3001
#define MAX(x,y) ((x)<(y)?(y):(x))
#define NULL_PARENT (-1)
using namespace std;

using Graph = vector<vector<int>>;
using LL = long long int;
int n;

// Use the first dimension to avoid cache miss
// parent(v, u): the parent of u when tree root at v
int parent[MAXN][MAXN];
// num_subtree_node[v][u]: the number of node in u's subtree rooted at v
int num_subtree_node[MAXN][MAXN];
// visit[v][u]: is u already visited in a tree rooted at v
bool visit[MAXN][MAXN] = {{false}};
// dis[v][u]: the dis to u in the tree rooted at v
int dis[MAXN][MAXN] = {{0}};
// table[v][u]: the max S to u in the tree rooted at v
LL table[MAXN][MAXN] = {{0}};

int dfs(int current, int par, int root, Graph &g){
    // save current's parent
    parent[root][current] = par;
    visit[root][current] = true;
    int num_node = 1; // itself
    for(int child:g[current]){
        if(visit[root][child] == false){
            num_node += dfs(child, current, root, g);
        }
    }
    num_subtree_node[root][current] = num_node;
    return num_node;
}

LL dp(Graph &g){
    vector<queue<int>> q(n); // q(u) is the bfs queue rooted at u
    for(int u = 0; u < n; u++){
        q[u].push(u); // the tree rooted at u
        dis[u][u] = 0; // the distance from u to u
        fill(visit[u], visit[u] + n, false); // initialize visit rooted at u
        table[u][u] = 0LL;//
        visit[u][u] = true; // visit[u][u] is true
    }
    bool all_empty = false;
    LL max_S = -1;
    // dp over the length (1, 2, ..., )
    // Complexity: O(n) * (O(n)(number of nodes) + O(n)(redundant step))
    // if all queues are empty, we end the dynamic programming procedure
    for(int length = 1; all_empty == false; length++){
        all_empty = true;
        // loop over each bfs queue
        // each tree is rooted at u
        for(int u = 0; u < n; u++){
            while(true){
                if(q[u].empty() == false){
                    all_empty = false;
                }else break;
                int v = q[u].front(); // the node to expand
                // the distance from u to v
                if(dis[u][v] == length){
                    // if the distance from u to v is
                    // dis[u][v] == length
                    break;
                } else q[u].pop();
                // only update distance from uj to child == length
                // update v's children section
                for(int child: g[v]){
                    // if child in a tree rooted u's visit flag is false
                    // , we will update this node
                    if(visit[u][child] == false){
                        // update distance
                        dis[u][child] = dis[u][v] + 1;

                        // dp step
                        if(u != v){
                            // their parent must exist
                            assert(parent[child][u] != -1
                                && parent[u][child] != -1);
                            table[u][child] = \
                                MAX(table[u][parent[u][child]],
                                    table[parent[child][u]][child])\
                                + \
                                num_subtree_node[u][child] *
                                num_subtree_node[child][u];
                        }
                        // base case: length == 1
                        else{
                            table[u][child] = \
                                num_subtree_node[u][child] *
                                num_subtree_node[child][u];
                            assert(length == 1);
                        }
                        // put this node in the q[u]
                        q[u].push(child);
                        // mark this as visited
                        visit[u][child] = true;

                        // update max_S
                        if(table[u][child] > max_S){
                            max_S = table[u][child];
                        }
                    }
                }
            }
        }
    }

    return max_S;
}

LL solve(Graph &g){
    // precompute parent[u][v], num_subtree_node[u][v]
    // complexity: O(n^2)
    for(int u = 0, ret; u < n; u++){
        ret = dfs(u, NULL_PARENT, u, g);
        assert(ret == n);
    }
    // compute dp[u][v]
    LL max_S = dp(g);
    return max_S;
}


int main(){
    cin >> n;
    Graph g(n);
    for(int i = 0, u, v; i < n-1; i++){
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << solve(g) << "\n";
    return 0;
}
