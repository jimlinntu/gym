/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node*, NodeCopy*> map = {{nullptr, nullptr}};
    NodeCopy *traverse(Node *root){
        if(root == nullptr) return nullptr;
        NodeCopy *c = nullptr;
        // if it already exists, we will use it
        if(map.find(root) != map.end()) c = map[root];
        else c = map[root] = new NodeCopy(root->val);

        c->left = traverse(root->left);
        c->right = traverse(root->right);

        // a random pointer has 2 cases
        // Case 1: point to a node which is already copied
        //         e.g. point to its ancestor, or left side sibling
        // Case 2: point to a node which is not copied yet
        //         In this case, we will precreate that node

        if(map.find(root->random) != map.end()) c->random = map[root->random];
        else c->random = map[root->random] = new NodeCopy(root->random->val);

        return c;
    }
        
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy *c = traverse(root);
        return c;
    }
};
