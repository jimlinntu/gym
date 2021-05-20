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
    Node *find_leftmost(Node *cur){
        for(; cur != nullptr; cur = cur->next){
            if(cur->left) return cur->left;
            if(cur->right) return cur->right;
        }
        return nullptr;
    }
    // Complexity: O(n)
    // Because each node will be visited at most twice
    // The first time is when solve(cur) is called
    // The second time is when find_leftmost() scans through it
    // Note that a node cannot not be scanned through find_leftmost more than 1 time
    // Because find_leftmost will only be triggered if a node has at least one child
    // Later this node's child will "protect" nodes on its right being scanned
    void solve(Node *cur){
        if(cur == nullptr) return;
        Node *leftmost = nullptr;
        if(cur->left or cur->right){
            // Only scan through if cur has at least one children
            // NOTE: This is a crucial step to reduce the time complexity
            //       to O(n)!
            leftmost = find_leftmost(cur->next);
        }
        if(cur->left and cur->right){
            cur->left->next = cur->right;
            cur->right->next = leftmost;
        }else if(cur->left){
            cur->left->next = leftmost;
        }else if(cur->right){
            cur->right->next = leftmost;
        }
        // right side must be completed first
        solve(cur->right);
        solve(cur->left);
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};
