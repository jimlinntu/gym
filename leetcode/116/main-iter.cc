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
        // Idea:
        // Connect nodes level by level
        Node *cur = root;
        while(cur){
            Node *next_level_first = cur->left;
            for(; cur != nullptr; cur = cur->next){
                if(cur->left){
                    cur->left->next = cur->right;
                }
                if(cur->right and cur->next){
                    cur->right->next = cur->next->left;
                }
            }
            // Jump the first node on the next level
            cur = next_level_first;
        }
        return root;
    }
};
