/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, vector<int>> adj;

    void fill_adj(Node *node){
        unordered_set<Node*> visited;
        queue<Node*> q;
        if(node != nullptr){
            q.push(node);
            visited.insert(node);
        }
        while(!q.empty()){
            Node *cur = q.front();
            q.pop();
            adj[cur->val]; // create an empty list
            for(Node *nei: cur->neighbors){
                // push the id of that node
                adj[cur->val].push_back(nei->val);
                if(visited.find(nei) != visited.end()) continue;
                visited.insert(nei);
                q.push(nei);
            }
        }
    }

    Node *build_graph(Node *root){
        int n = adj.size();
        vector<Node*> g(101, nullptr);
        for(auto &p: adj){
            g[p.first] = new Node(p.first);
        }
        for(auto &p: adj){
            vector<int> &nei_ids = p.second;
            for(int j = 0; j < nei_ids.size(); j++){
                // add the node's memory address
                g[p.first]->neighbors.push_back(g[nei_ids[j]]);
            }
        }
        if(root != nullptr) return g[root->val];
        else return nullptr;
    }

    Node* cloneGraph(Node* node) {
        fill_adj(node);
        return build_graph(node);
    }
};
