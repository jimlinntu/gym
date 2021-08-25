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
    
    // CFG:
    // <Node> -> root->val,num:<Node-1><Node-2>...<Node-num>#
    // <Node> -> # (if that node is a nullptr)
    void encode(Node *root, string &s){
        if(root == nullptr){
            s += "#";
            return;
        }
        s += to_string(root->val) + "," + to_string(root->children.size()) + ":";
        for(Node *cur: root->children){
            encode(cur, s);
        }
        s += "#"; // end of this substree
    }
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        encode(root, s);
        return s;
    }
    // Top down parser
    // <Node> -> root->val,num:<Node-1><Node-2>...<Node-num>#
    // <Node> -> # (if that node is a nullptr)
	Node *decode(string &s, int &cur){
        if(s[cur] == '#'){
            cur++; // consume a character
            return nullptr;
        }
        int idx = s.find(',', cur);
        Node *root = new Node(stoi(s.substr(cur, idx-cur)));
        
        int idx2 = s.find(':', idx);
        int num_children = stoi(s.substr(idx+1, idx2-idx-1));
        cur = idx2+1;
        for(int i = 0; i < num_children; i++){
            root->children.push_back(decode(s, cur));
        }
        assert(s[cur] == '#');
        cur++;
        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int cur = 0;
        return decode(data, cur);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
