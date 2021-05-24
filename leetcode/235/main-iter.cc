/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert(root != nullptr);
        TreeNode *cur = root;
        // O(log n) time
        while(cur != nullptr){
            int pv = p->val, qv = q->val, v = cur->val;
            if(pv < v and qv < v){
                cur = cur->left;
            }else if(pv > v and qv > v){
                cur = cur->right;
            }else if(pv == v or qv == v){
                // p is under q (or q is under p)
                return cur;
            }else return cur; // On different subtrees
        }
        assert(false);
        return nullptr;
    }
};
