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

struct QuadTree {
    int n;
    Node *root;
    QuadTree(vector<vector<int>> &grid){
        n = grid.size();
        if(n == 0){
            root = nullptr;
            return;
        }else root = new Node();
        build(root, grid, 0, n, 0, n);
    }
    
    bool issame(vector<vector<int>> &grid,
                int row_start, int row_end,
                int col_start, int col_end){
        int val = grid[row_start][col_start];
        for(int i = row_start; i < row_end; i++){
            for(int j = col_start; j < col_end; j++){
                if(val != grid[i][j]) return false;
            }
        }
        return true;
    }
    // Let N = n*n
    // O(N log4 N)
    // because at each level of the tree
    // we have to traverse at worst the whole tree
    void build(Node *cur, vector<vector<int>> &grid,
               int r1, int r2, int c1, int c2){
        assert(cur != nullptr);
        if(issame(grid, r1, r2, c1, c2)){
            cur->val = grid[r1][c1];
            cur->isLeaf = true;
        }else{
            // Divide [r1, r2, c1, c2] into 4 boxes
            int rmid = (r1+r2)/2;
            int cmid = (c1+c2)/2;
            cur->isLeaf = false;
            cur->topLeft = new Node();
            cur->topRight = new Node();
            cur->bottomLeft = new Node();
            cur->bottomRight = new Node();
            // check each grid separately
            build(cur->topLeft, grid, r1, rmid, c1, cmid);
            build(cur->topRight, grid, r1, rmid, cmid, c2);
            build(cur->bottomLeft, grid, rmid, r2, c1, cmid);
            build(cur->bottomRight, grid, rmid, r2, cmid, c2);
        }
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        QuadTree qt(grid);
        return qt.root;
    }
};
