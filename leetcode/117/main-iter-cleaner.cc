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
    Node* connect(Node* root) {
        Node *cur = root;
        for(Node *next_level_start; cur != nullptr; cur = next_level_start){
            next_level_start = nullptr;
            for(Node *prev = nullptr; cur != nullptr; cur = cur->next){
                // prev indicates the previous child on the left of cur->left
                if(cur->left){
                    if(prev) prev->next = cur->left;
                    prev = cur->left; // update the previous one
                    if(next_level_start == nullptr) next_level_start = cur->left;
                }
                if(cur->right){
                    if(prev) prev->next = cur->right;
                    prev = cur->right;
                    if(next_level_start == nullptr) next_level_start = cur->right;
                }
            }
        }
        return root;
    }
};
