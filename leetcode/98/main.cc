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
using L = long int;
using Minmax = pair<long int, long int>;

Minmax get_value(TreeNode *current, int parent_value, bool &ans){
    Minmax left;
    if(current->left != nullptr){
       left = get_value(current->left, current->val, ans);
    }else left = Minmax(current->val, (L)current->val-1); // min value should be itself, max value will be less than 1 so that it can be smaller than current->val

    Minmax right;
    if(current->right != nullptr){
        right = get_value(current->right, current->val, ans);
    }else right = Minmax((L)current->val+1, current->val); // max value should be itself, min value will be less than 1 so that it can be larger than current->val

    // left.max < current.val and right.min > current.val
    if(left.second < current->val and right.first > current->val){
        return Minmax(left.first, right.second); // return this subtree's min and max
    }
    ans = false;
    return Minmax((L)parent_value + 1, (L)parent_value - 1); // intend to early break the recursion (because parent_value must be < parent + 1 or parent_value > parent - 1)
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        bool ans = true;
        get_value(root, root->val, ans);
        return ans;
    }
};
