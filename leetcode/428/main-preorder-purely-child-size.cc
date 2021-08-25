/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    void enc(Node *root, string &s){
        if(root == nullptr){
            s += "N"; // nullptr
            // Ex. A root may have [Node, null, Node, null]
            return;
        }
        s += to_string(root->val) + "," + to_string(root->children.size()) + ":";
        for(Node *c: root->children){
            enc(c, s);
        }
    }
    string serialize(Node* root) {
        string s;
        enc(root, s);
        return s;
    }

    Node* dec(string &s, int &cur){
        if(s[cur] == 'N'){
            cur++;
            return nullptr;
        }
        int idx = s.find(',', cur);
        int val = stoi(s.substr(cur, idx-cur));
        Node *root = new Node(val);
        int idx2 = s.find(':', idx);
        int num_children = stoi(s.substr(idx+1, idx2-idx-1));
        // consume "root->val,num:"
        cur = idx2+1;
        for(int i = 0; i < num_children; i++){
            root->children.push_back(dec(s, cur));
        }
        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int cur = 0;
        Node *root = dec(data, cur);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
