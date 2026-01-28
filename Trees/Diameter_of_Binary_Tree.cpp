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
**/

// Recursive Approach TC O(N^2) SC O(H) - BFS
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);
        int diameter = leftHeight + rightHeight;
        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

        return max(diameter, sub);
    }

    int maxHeight(TreeNode* node){
        if(!node) return 0;

        return 1 + max(maxHeight(node->left), maxHeight(node->right));
    }
};

// Recursive Approach TC O(N) SC O(H) - DFS 
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        if(!root)
            return 0;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* node, int& res){
        if(!node)
            return 0;
        int left = dfs(node->left, res);
        int right = dfs(node->right, res);
        int diameter = left + right;
        res = max(res, diameter);
        return 1 + max(left, right);
    }
};
