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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int max_width = 1;
        // the number of null nodes on the left
        // when we want to reach the leftmost non-null node
        // For a node, if there is no non-null nodes on its left, we say this node's
        // num_null value is 0
        unordered_map<TreeNode*, int> num_null;
        queue<TreeNode*> q;
        num_null[root] = 0;
        q.push(root);
        while(!q.empty()){
            int null_nodes = 0; // # of null nodes
            int width = 0; // # of non-null and null nodes
            // Loop over the nodes on the same level in this tree
            for(int i = q.size(); i > 0; i--){
                TreeNode *cur = q.front();
                q.pop();


                if(width != 0){
                    // Expand the null nodes from the parent level
                    null_nodes += 2 * num_null[cur];
                }

                if(cur->left != nullptr){
                    if(width == 0) width = 1;
                    else width += null_nodes + 1;

                    num_null[cur->left] = null_nodes;
                    q.push(cur->left);
                    null_nodes = 0; // reset
                    max_width = max(max_width, width);
                }else if(width != 0){
                    null_nodes += 1;
                }

                if(cur->right != nullptr){
                    if(width == 0) width = 1;
                    else width += null_nodes + 1;

                    num_null[cur->right] = null_nodes;
                    q.push(cur->right);
                    null_nodes = 0; // reset
                    max_width = max(max_width, width);
                }else if(width != 0){
                    null_nodes += 1;
                }
            }
        }
        return max_width;
    }
};
