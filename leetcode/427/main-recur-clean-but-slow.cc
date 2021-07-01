/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, n, 0, n);
    }

    // Assume all numbers are different
    // we recursively break each space into 4 boxes
    // if 4 boxes are of same value, we know that they can be merged into 1 node
    // Complexity: Let N = n*n, n = 2^x
    // O(1) + O(4) + .... O(4^x) = O(4^x) = O(N)
    Node* build(vector<vector<int>> &grid,
                int r1, int r2, int c1, int c2){
        if(r2-r1 == 1 and c2-c1 ==1){
            return new Node(grid[r1][c1], true);
        }
        // Assume this is not a leaf node
        Node *ret = new Node();
        int rmid = (r1+r2)/2, cmid = (c1+c2)/2;
        // break into 4 parts
        Node *topLeft = build(grid, r1, rmid, c1, cmid);
        Node *topRight = build(grid, r1, rmid, cmid, c2);
        Node *botLeft = build(grid, rmid, r2, c1, cmid);
        Node *botRight = build(grid, rmid, r2, cmid, c2);
        // if they can be merged
        if(topLeft->isLeaf and topRight->isLeaf and botLeft->isLeaf and botRight->isLeaf
           and topLeft->val == topRight->val and topRight->val == botLeft->val
           and botLeft->val == botRight->val){
            ret->val = grid[r1][c1];
            ret->isLeaf = true;
            delete topLeft;
            delete topRight;
            delete botLeft;
            delete botRight;
        }else{
            ret->isLeaf = false;
            ret->topLeft = topLeft;
            ret->topRight = topRight;
            ret->bottomLeft = botLeft;
            ret->bottomRight = botRight;
        }
        return ret;
    }
};
