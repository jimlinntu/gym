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
    Node* traverse(Node *node){
        unordered_map<Node*, Node*> map;
        Node *ret = nullptr;
        bool visited[101] = {false};
        queue<Node*> q;
        if(node != nullptr){
            ret = new Node(node->val);
            visited[node->val] = true;
            // map old to new
            map[node] = ret;
            q.push(node);
        }

        while(!q.empty()){
            Node *cur = q.front();
            q.pop();

            map[cur]->neighbors = cur->neighbors; // point to nodes in the old graph

            for(Node* nei: cur->neighbors){
                if(visited[nei->val]) continue;
                visited[nei->val] = true;
                Node *copy = new Node(nei->val);
                map[nei] = copy;
                q.push(nei);
            }
        }

        // Turn old nodes into new nodes
        for(auto &p: map){
            vector<Node*> &neighbors = p.second->neighbors;
            for(int i = 0; i < neighbors.size(); i++){
                // map the old node to the new node
                neighbors[i] = map[neighbors[i]];
            }
        }
        return ret;
    }

    Node* cloneGraph(Node* node) {
        return traverse(node);
    }
};
