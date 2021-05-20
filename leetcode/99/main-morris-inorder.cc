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
    TreeNode *first_mismatch = nullptr; // larger one
    TreeNode *second_mismatch = nullptr; // smaller one
    TreeNode *true_first = nullptr;
    TreeNode *prev = nullptr;
    void visit(TreeNode *cur){
        assert(cur != nullptr);
        if(prev and prev->val > cur->val){
            // record the larger one
            if(first_mismatch == nullptr) first_mismatch = prev;
            // record the smaller one
            second_mismatch = cur;
        }
        prev = cur;
    }
    // O(n): Morris Traversal
    void spot_first_and_second_mismatch(TreeNode *root){
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                // pred is the predecessor of cur (in terms of inorder)
                TreeNode *pred = cur->left;
                while(pred->right != nullptr and
                        pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == cur){
                    // we should remove the link
                    pred->right = nullptr;
                    // Visit current
                    visit(cur);
                    // move to the right
                    cur = cur->right;
                }else{
                    assert(pred->right == nullptr);
                    pred->right = cur;
                    cur = cur->left;
                }
            }else{
                // Visit current
                visit(cur);
                cur = cur->right;
            }
        }
    }
    void update_first_second(TreeNode *cur){
        // use the leftmost one
        // Ex. 2 3 3 3 3 -->(swap) --> 3 3 3 2 3
        //                             ^   ^<------- first_mismatch
        //                            true_first
        if(true_first == nullptr and cur->val == first_mismatch->val){
            true_first = cur;
        }
        // use the rightmost one
        // Ex. 2 2 2 2 3 -->(swap) --> 2 3 2 2 2
        //                                 ^>------- second_mismatch
        //                                     ^<--- the one we want
        if(cur->val == second_mismatch->val) second_mismatch = cur;
    }
    // O(n): Morris Traversal to find the "true" first and second mismatch
    // (Please see my slides for more info)
    // This is to handle Case 2 & Case 3:
    // we must choose the leftmost node that == first_mismatch->val
    // and choose the rightmost node that == second_mismatch->val
    // It will not be necessary if this BST contains no duplicates
    void choose_leftmost_rightmost_true_mismatch(TreeNode *root){
        prev = nullptr; // reset it
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                // pred is the predecessor of cur (in terms of inorder)
                TreeNode *pred = cur->left;
                while(pred->right != nullptr and
                        pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == cur){
                    // we should remove the link
                    pred->right = nullptr;
                    // Visit current
                    update_first_second(cur);
                    // move to the right
                    cur = cur->right;
                }else{
                    assert(pred->right == nullptr);
                    pred->right = cur;
                    cur = cur->left;
                }
            }else{
                // Visit current
                update_first_second(cur);
                cur = cur->right;
            }
        }
    }
    void recoverTree(TreeNode* root) {
        // O(n)
        spot_first_and_second_mismatch(root);
        // O(n)
        choose_leftmost_rightmost_true_mismatch(root);

        assert(true_first and second_mismatch);

        swap(true_first->val, second_mismatch->val);
    }
};
