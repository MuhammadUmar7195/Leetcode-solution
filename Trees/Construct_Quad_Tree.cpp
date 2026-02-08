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

// using DFS to construct the quad tree TC: O(n^2) SC: O(logn)
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
private:
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c){
        if(n == 1){
            return new Node(grid[r][c] == 1, true);
        }

        int mid = n / 2;
        Node* topLeft = dfs(grid, mid, r, c);
        Node* topRight = dfs(grid, mid, r, c + mid);
        Node* bottomLeft = dfs(grid, mid, r + mid, c);
        Node* bottomRight = dfs(grid, mid, r + mid, c + mid);

        if(topLeft->isLeaf
        && topRight->isLeaf
        && bottomLeft->isLeaf
        && bottomRight->isLeaf
        && topLeft->val == topRight->val
        && topLeft->val == bottomLeft->val 
        && topLeft->val == bottomRight->val){
            return new Node(topLeft->val, true);
        }

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};