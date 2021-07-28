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
class Solution {
public:
    int sum = 0;
    void visit(TreeNode *cur){
        sum += cur->val;
        cur->val = sum;
    }
    void morris_inorder(TreeNode *root){
        TreeNode *cur = root;
        // Each node will be traverse at most 4 times
        // O(4n) = O(n)
        while(cur != nullptr){
            // Find this node's successor in terms of its inorder
            TreeNode *t = cur->right;
            // Go as left as possible (cur's inorder successor)
            while(t and t->left != nullptr and t->left != cur){
                t = t->left;
            }

            // there is a right subtree
            if(t){
                if(t->left == cur){
                    t->left = nullptr; // clean up
                    // visit cur
                    visit(cur);
                    cur = cur->left;
                }else{
                    // build a link so that we can go back to this node later
                    t->left = cur;
                    cur = cur->right;
                }
            }else{
                // there is no right subtree
                // visit cur
                visit(cur);
                cur = cur->left;
            }
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        morris_inorder(root);
        return root;
    }
};
