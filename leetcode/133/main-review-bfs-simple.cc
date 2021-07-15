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
        // can be a hashmap if node->val's range is undetermined
        Node *graph[101] = {nullptr};
        graph[node->val] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node *cur = q.front();
            Node *copycur = graph[cur->val];
            q.pop();
        
            for(Node *nei: cur->neighbors){
                // visited
                if(graph[nei->val] != nullptr){
                    // add this copy node to its neighbor
                    copycur->neighbors.push_back(graph[nei->val]);
                    continue;
                }
                // first time visiting this node
                graph[nei->val] = new Node(nei->val);
                copycur->neighbors.push_back(graph[nei->val]);

                q.push(nei);
            }
        }

        return graph[node->val];
    }
};
