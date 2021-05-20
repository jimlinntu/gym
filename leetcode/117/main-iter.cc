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
    Node* find_next_node_contains_children(Node *cur){
        for(; cur != nullptr; cur = cur->next){
            // it this node has at least one child
            if(cur->left or cur->right) return cur;
        }
        return nullptr;
    }
    Node* connect(Node* root) {
        Node *cur = root;
        while(cur){
            // We will start from the node that contains at least one child
            cur = find_next_node_contains_children(cur);
            Node *level_start = nullptr;
            if(cur) level_start = (cur->left)? (cur->left):(cur->right);
            Node *next;
            for(; cur != nullptr; cur = next){
                next = find_next_node_contains_children(cur->next);
                if(next) assert(next->left or next->right);
                // both exist
                if(cur->left and cur->right){
                    cur->left->next = cur->right;
                    if(next){
                        if(next->left) cur->right->next = next->left;
                        else cur->right->next = next->right;
                    }
                }else if(cur->left){
                    // only left exists
                    if(next){
                        if(next->left) cur->left->next = next->left;
                        else cur->left->next = next->right;
                    }
                }else if(cur->right){
                    // only right exists
                    if(next){
                        if(next->left) cur->right->next = next->left;
                        else cur->right->next = next->right;
                    }
                }else assert(false); // because cur must contain at least one child
            }
            cur = level_start;
        }
        return root;
    }
};
