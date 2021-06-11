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

struct TreeIterator {
    TreeNode *root;
    TreeNode *cur;
    stack<TreeNode*> s;
    bool forward;

    TreeIterator(TreeNode *r, TreeNode *c, bool f): forward(f){
        assert(c != nullptr);
        root = r;
        cur = root;
        // Record the path
        // (NOTE: we only record nodes that will appear
        //  after `c` if forward == true)
        while(cur != c){
            if(c->val < cur->val){
                if(f) s.push(cur);
                cur = cur->left;
            }else{
                // The reason why when forward == false we don't have to record cur
                // is because cur is already visited when we consider its inorder order!
                if(!f) s.push(cur);
                cur = cur->right; // NOTE: do not need to push this node into the stack
            }
        }
        assert(cur != nullptr);
        s.push(cur);
        // Walk one step
        if(forward) this->next();
        else this->prev();
    }

    TreeNode *prev(){
        assert(!forward);
        if(s.empty()) return nullptr;
        TreeNode *ret = s.top();
        s.pop();
        cur = ret->left;
        // Go as right as possible
        while(cur != nullptr){
            s.push(cur);
            cur = cur->right;
        }
        return ret;
    }

    TreeNode *next(){
        assert(forward);
        if(s.empty()) return nullptr;
        TreeNode *ret = s.top();
        s.pop();
        cur = ret->right;
        // Go as left as possible
        while(cur != nullptr){
            s.push(cur);
            cur = cur->left;
        }
        return ret;
    }
};

class Solution {
public:
    TreeNode* find_closest(TreeNode *root, double target){
        // Find the closest node
        TreeNode *closest = root;
        TreeNode *cur = root;
        while(cur){
            if((double)cur->val == target){
                closest = cur;
                break;
            }
            if(abs(target - cur->val) < abs(target - closest->val))
                closest = cur;
            if(cur->val < target){
                // the node on the left side must have greater different
                cur = cur->right;
            }else{
                cur = cur->left;
            }
        }
        return closest;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(root == nullptr) return {};
        if(k == 0) return {};

        TreeNode *closest = find_closest(root, target);
        // O(2 * log n)
        TreeIterator it_next(root, closest, true);
        TreeIterator it_prev(root, closest, false);
        TreeNode *next = it_next.next();
        TreeNode *prev = it_prev.prev();
        vector<int> ans;
        ans.push_back(closest->val);
        // O(k) in average
        // (when k == n because each node will only be visited as most twice)
        while(--k > 0){
            if(next == nullptr){
                assert(prev != nullptr);
                ans.push_back(prev->val);
                prev = it_prev.prev(); // update
            }else if(prev == nullptr){
                ans.push_back(next->val);
                next = it_next.next(); // update
            }else{
                // Choose on with smaller |target - val|
                if(abs(target - prev->val) <= abs(target - next->val)){
                    ans.push_back(prev->val);
                    prev = it_prev.prev();
                }else{
                    ans.push_back(next->val);
                    next = it_next.next();
                }
            }
        }
        return ans;
    }
};
