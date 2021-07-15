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

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        stack<Node*> stk;
        stk.push(node);
        graph[node->val] = new Node(node->val);

        while(!stk.empty()){
            Node *cur = stk.top();
            Node *copycur = graph[cur->val];
            stk.pop();

            for(Node *nei: cur->neighbors){
                if(graph[nei->val]){
                    copycur->neighbors.push_back(graph[nei->val]);
                }else{
                    Node *copynei = graph[nei->val] = new Node(nei->val);
                    copycur->neighbors.push_back(copynei);
                    stk.push(nei);
                }
            }
        }
        return graph[node->val];
    }
};
