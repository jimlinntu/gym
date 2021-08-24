/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void _s(TreeNode *root, string &s){
        if(root != nullptr){
            s += to_string(root->val) + ",";
            _s(root->left, s);
            _s(root->right, s);
        }
        s += "#"; // end of this subtree
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        _s(root, s);
        return s;
    }

    // `cur` is like a cursor pointing to the next character
    TreeNode* _d(string &s, int &cur){
        if(s[cur] == '#'){
            cur++;
            return nullptr;
        }
        int idx = s.find(',', cur);
        int val = stoi(s.substr(cur, idx-cur));
        TreeNode *root = new TreeNode(val);
        cur = idx+1;

        root->left = _d(s, cur);
        root->right = _d(s, cur);

        // consume # at the end
        assert(s[cur] == '#');
        // consume that '#'
        cur++;
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int cur = 0;
        TreeNode *root = _d(data, cur);
        assert(cur == data.size());
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
