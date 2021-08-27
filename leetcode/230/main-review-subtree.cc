/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Node{
    int val;
    Node *left, *right;
    int subsum;
};

class Solution {
public:
    Node* build(TreeNode *cur){
        if(cur == nullptr) return nullptr;
        Node *node = new Node();
        node->val = cur->val;
        node->left = build(cur->left);
        node->right = build(cur->right);
        node->subsum = 1;
        if(node->left) node->subsum += node->left->subsum;
        if(node->right) node->subsum += node->right->subsum;
        return node;
    }
    Node *bsearch(Node *cur, int k){
        int left = 0, right = 0;
        if(cur->left) left = cur->left->subsum;
        if(cur->right) right = cur->right->subsum;

        if(k == left+1) return cur;
        else if(k < left+1){
            return bsearch(cur->left, k);
        }else{
            return bsearch(cur->right, k-left-1);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        Node *root2 = build(root);
        Node *ans = bsearch(root2, k);
        return ans->val;
    }
};
