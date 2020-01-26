#include <bits/stdc++.h>
using namespace std;
int n;

using Graph = vector<vector<int>>;

void bfs(int start_node_idx, Graph &graph, int &deepest_node_idx, vector<int> *backtracker=nullptr){
    queue<int> q;
    vector<bool> visit(n); // record i's node has been visited
    vector<int> distance(n); // the distance from start_node_idx to i
    int max_distance = -1; // record the deepest one

    q.push(start_node_idx);
    visit[start_node_idx] = true;
    distance[start_node_idx] = 0;
    // breadth-first search
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        // update the deepest distance
        if(distance[current] > max_distance){
            max_distance = distance[current];
            deepest_node_idx = current;
        }

        // loop over all the neighbors
        for(auto neighbor_idx:graph[current]){
            if(!visit[neighbor_idx]){
                // push its neighbor into the queue
                q.push(neighbor_idx);
                // record it has been visited
                visit[neighbor_idx] = true;
                // update the distance
                distance[neighbor_idx] = distance[current] + 1;
                if(backtracker != nullptr){
                    (*backtracker)[neighbor_idx] = current;
                }
            }
        }
    }
}

void dfs(Graph &graph, int current, vector<bool> &visit, vector<bool> &on_path, 
        int &subtree_depth, int &subtree_deepest_node_idx, 
        int &third_depth, int &third_node_idx){
    bool has_no_children = true;
    int max_depth = -1, max_depth_node_idx; // record the depth of tree rooted at `current` index
    // loop over all neighbors
    for(auto child:graph[current]){
        if(!visit[child]){
            has_no_children = false;
            visit[child] = true; // avoid dfs looping

            int child_subtree_depth, child_subtree_deepest_node_idx;
            if(on_path[current] && (!on_path[child])){
                dfs(graph, child, visit, on_path, child_subtree_depth, child_subtree_deepest_node_idx,
                    third_depth, third_node_idx);

                // update
                if(child_subtree_depth > third_depth){
                    third_depth = child_subtree_depth;
                    third_node_idx = child_subtree_deepest_node_idx;
                }
            }else{
                dfs(graph, child, visit, on_path, child_subtree_depth, child_subtree_deepest_node_idx,
                    third_depth, third_node_idx);
            }

            // save max depth
            if(child_subtree_depth > max_depth){
                max_depth = child_subtree_depth;
                max_depth_node_idx = child_subtree_deepest_node_idx;
            }
        }
    }

    // base case
    if(has_no_children){
        subtree_depth = 0;
        subtree_deepest_node_idx = current;
    }else{
        subtree_depth = max_depth + 1;
        subtree_deepest_node_idx = max_depth_node_idx;
    }
}

int fill_on_path(int start_idx, vector<int> &backtracker, vector<bool> &on_path){
    int current = start_idx;
    int depth = 0;
    while(true){
        on_path[current] = true;
        // move the index what backtracker points to
        current = backtracker[current];
        if(current != -1) depth++;
        else break;
    }
    return depth;
}

void find_the_longest_path(Graph &graph, int &res, int &a, int &b, int &c){
    // *forward BFS: find the first endpoint
    int deepest_node_idx;
    bfs(0, graph, deepest_node_idx);
    // *backward BFS: find the second endpoint
    int another_endpoint_idx;
    vector<int> backtracker(n, -1);
    bfs(deepest_node_idx, graph, another_endpoint_idx, &backtracker);

    vector<bool> on_path(n);
    int depth = fill_on_path(another_endpoint_idx, backtracker, on_path);
    // *utilize one of the endpoints as root,
    vector<bool> visit(n);
    int third_depth = -1, third_node_idx = -1;
    int subtree_depth, subtree_deepest_node_idx;
    dfs(graph, deepest_node_idx, visit, on_path, subtree_depth, subtree_deepest_node_idx,
        third_depth, third_node_idx);

    if(third_depth != -1){
        third_depth++; // add the missing one distance
        res = depth + third_depth;
        a = deepest_node_idx, b = another_endpoint_idx, c = third_node_idx;
    }
    // if all nodes are on a-b
    else{
        res = depth;
        a = deepest_node_idx, b = another_endpoint_idx;
        // randomly choose a point on a-b path, I choose the previous point for another_endpoint_idx
        c = backtracker[another_endpoint_idx];
        assert(c != -1);
    }
}

void solve(){
    int res, a, b, c;
    Graph graph(n);
    for(int i = 0; i < n-1; i++){
        cin >> a; cin >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    find_the_longest_path(graph, res, a, b, c);
    printf("%d\n%d %d %d\n", res, a+1, b+1, c+1);
}
int main(){
    cin >> n;
    solve();
    return 0;
}
