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
using LL = long long int;

struct Ret{
    LL maxPathSum;
    LL maxPathSumFrom;
};

Ret solve(TreeNode *current){
    if(current->left == nullptr and current->right == nullptr){
        return {.maxPathSum=current->val, .maxPathSumFrom=current->val};
    }
    
    Ret left_ret, right_ret;
    
    if(current->left != nullptr){
        left_ret = solve(current->left);
    }
    if(current->right != nullptr){
        right_ret = solve(current->right);
    }
    // maxPathSum and maxPathSumFrom have at least the current value
    LL maxPathSum = current->val;
    LL maxPathSumFrom = current->val;

    if(current->left == nullptr){
        // the right branch is available
        maxPathSum = max(maxPathSum, right_ret.maxPathSum);
        maxPathSum = max(maxPathSum, current->val + right_ret.maxPathSumFrom);

        maxPathSumFrom = max(maxPathSumFrom,
                             current->val + right_ret.maxPathSumFrom);
    }else if(current->right == nullptr){
        // the left branch is available
        maxPathSum = max(maxPathSum, left_ret.maxPathSum);
        maxPathSum = max(maxPathSum, current->val + left_ret.maxPathSumFrom);

        maxPathSumFrom = max(maxPathSumFrom,
                             current->val + left_ret.maxPathSumFrom);
    }else{
        // both branches are available
        // not pass the current node
        maxPathSum = max({maxPathSum, 
                          left_ret.maxPathSum,
                          right_ret.maxPathSum});
        
        // pass the current node
        maxPathSum = max({maxPathSum,
                          
                         current->val +
                         left_ret.maxPathSumFrom +
                         right_ret.maxPathSumFrom,
                          
                         current->val+left_ret.maxPathSumFrom,
                         
                         current->val+right_ret.maxPathSumFrom
                         });

        // path from the current node to one of its child
        maxPathSumFrom = max({maxPathSumFrom,
                              current->val+left_ret.maxPathSumFrom,
                              current->val+right_ret.maxPathSumFrom});
    }
    
    return {.maxPathSum=maxPathSum, .maxPathSumFrom=maxPathSumFrom};
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr){
            assert(false);
            return -1;
        }else{
            Ret ret = solve(root);
            return ret.maxPathSum;
        }
    }
};
