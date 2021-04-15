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

class BTIterator {
public:
    TreeNode *cur; // generally, it will contain a right child (execpt the root)
    bool forward;
    stack<TreeNode*> s;
    BTIterator(TreeNode *root, bool forward){
        cur = root;
        this->forward = forward;
    }

    bool has_next(){
        return cur != nullptr or !s.empty();
    }

    int next_val(){
        // all the way to the leftest node
        if(forward){
            for(; cur != nullptr; cur=cur->left){
                s.push(cur);
            }
        }else{
            for(; cur != nullptr; cur=cur->right){
                s.push(cur);
            }
        }
        assert(!s.empty());
        TreeNode *visit = s.top();
        s.pop();
        // move to the right node
        if(forward) cur = visit->right;
        else cur = visit->left;
        return visit->val;
    }
};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        // Solving two sums problem by two pointers
        // in O(n) time
        BTIterator forward_it(root, true);
        BTIterator backward_it(root, false);
        int start_val = forward_it.next_val(), end_val = backward_it.next_val();
        while(start_val < end_val){
            int sum = start_val + end_val;
            if(sum == k) return true;
            if(sum < k){
                // move to a bigger one
                start_val = forward_it.next_val();
            }else{
                // move to a smaller one
                end_val = backward_it.next_val();
            }
        }
        return false;
    }
};
