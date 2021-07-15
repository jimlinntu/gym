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
    Node *graph[101] = {nullptr};

    Node *dfs(Node *root){
        if(root == nullptr) return nullptr;
        // visited
        if(graph[root->val]) return graph[root->val];
        
        Node *copyroot = graph[root->val] = new Node(root->val);
        // add its neighbors
        for(Node *nei: root->neighbors){
            copyroot->neighbors.push_back(dfs(nei));
        }
        return copyroot;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
