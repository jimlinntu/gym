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
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        // nodes[val] == nullptr, this node does not exist
        // nodes[val] != nullptr, this node has been visited
        Node *nodes[101] = {nullptr};
        nodes[1] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        // BFS
        while(!q.empty()){
            Node *cur = q.front();
            q.pop();
            Node *cloned_cur = nodes[cur->val];
            for(auto neighbor: cur->neighbors){
                // it has not been visited
                if(nodes[neighbor->val] == nullptr){
                    // Create a cloned node
                    nodes[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // append this cloned neighbor
                cloned_cur->neighbors.push_back(nodes[neighbor->val]);
            }
            // After this loop, cur->val's corresponding node is set up
        }
        return nodes[1];
    }
};
