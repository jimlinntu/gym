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
    unordered_map<Node*, NodeCopy*> map;
    NodeCopy *traverse(Node *root){
        if(root == nullptr) return nullptr;
        NodeCopy *c = new NodeCopy(root->val);
        map[root] = c;
        c->left = traverse(root->left);
        c->right = traverse(root->right);
        return c;
    }

    void update_random(NodeCopy *croot, Node *root){
        if(root == nullptr) return;
        croot->random = map[root->random];
        update_random(croot->left, root->left);
        update_random(croot->right, root->right);
    }
        
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy *c = traverse(root);
        update_random(c, root);
        return c;
    }
};
