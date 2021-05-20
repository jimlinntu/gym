/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node *root, Node *prev){
        if(root == nullptr) return;
        if(prev) prev->next = root;
        solve(root->left, (prev)? (prev->right):(nullptr));
        solve(root->right, root->left);
    }
    Node* connect(Node* root) {
        solve(root, nullptr);
        return root;
    }
};
